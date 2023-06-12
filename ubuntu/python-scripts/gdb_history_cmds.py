import subprocess
import os
import readline

def fzf_history():
    # TODO: append command executed to gdb_history?
    HISTORY_FILE = "~/.gdb_history"
    CMD_HISTORY_FILE = "~/.gdb_cmd_history"
    gdb_cmd = ""

    # .gdb_history is only flushed when gdb exits, so use "show commands" to get
    # access to commands from the current session
    hist = gdb.execute("show commands", to_string=True)
    hist += gdb.execute("show commands +", to_string=True).rstrip()
    os.system("echo '" + hist + "' | tr -s ' ' | cut -f2- -d' ' | tac | awk '!a[$0]++' | tac > ~/.gdb_cmd_history")
    fzf_cmd = "cat " + HISTORY_FILE + " " + CMD_HISTORY_FILE + " | tac | awk '!x[$0]++' | tac | fzf --no-sort --tac"
    try:
        gdb_cmd = subprocess.check_output(fzf_cmd, shell=True).rstrip().decode("utf-8")
        print(gdb_cmd)
    except:
        print("༼ つ ◕_◕ ༽つ yeet")
    return gdb_cmd

class FzfHistory (gdb.Command):
    """Run history commands using fzf in gdb"""

    def __init__(self):
        super(FzfHistory, self).__init__("fzf", gdb.COMMAND_USER)

    def invoke(self, arg, from_tty):
        cmd = fzf_history()
        gdb.execute(cmd)
        # Add to readline history as if it was executed in the terminal
        readline.add_history(cmd)

NUM_FAST_CMDS = 3
class FastCommand(gdb.Command):
    def __init__(self):
        super(FastCommand, self).__init__("fastcmd", gdb.COMMAND_USER)
        fq_cmd = "define fq\n"
        for i in range(1, NUM_FAST_CMDS+1):
            fq_cmd += "f{}q\n".format(i)
            # TODO: convert these to an alias passing a command to fastcmd, e.g.
            # fastcmd print 1 or fastcmd execute 1
            # gdb.execute("alias f{0}. = fastcmd {0}".format(i))
            gdb.execute("define f{0}.\nfastcmd {0}\nend".format(i))
            gdb.execute("define f{0}q\n! sed -n '/^define f{0}/,/^#F{0}_INSERT_MARKER/".format(i) + "{//!p;}' ~/.gdbinit\nend")
        fq_cmd += "end"
        gdb.execute(fq_cmd)

    def invoke(self, arg, from_tty):
        if arg.isdigit():
            cmd_num = arg
            try:
                cmds = input("Enter f{} command: ".format(cmd_num))
                if cmds == "":
                    cmds = fzf_history()
                # Delete previous command definition
                os.system("sed -i '/define f" + cmd_num + "/,/#F" + cmd_num + "_INSERT_MARKER/{//!d}' ~/.gdbinit")
                # Insert f{}q to print out command to be executed
                os.system("sed -i '/^#F{0}_INSERT_MARKER/i \  f{0}q' ~/.gdbinit".format(cmd_num))
                for cmd in cmds.split(";"):
                    print(cmd)
                    os.system("sed -i '/^#F{}_INSERT_MARKER/i \  {}' ~/.gdbinit".format(cmd_num, cmd))
                # use to_string to suppress error output
                gdb.execute("source ~/.gdbinit", to_string=True)
            except KeyboardInterrupt:
                print("༼ つ ◕_◕ ༽つ yeet")

FzfHistory()
FastCommand()

import fileinput
import os
import readline
import subprocess

# Can change context to local repo using context switcher
# TODO: add option for tmux selected address to be made into breakpoint
# TODO: add option for emacs selected address to set to default breakpoint or
# just entire region with breakpoint

def save_cmd(cmd_num, cmd_str):
    key = "g{}".format(cmd_num)
    # script_dir = os.path.dirname(os.path.realpath(__file__))
    # def_file = os.path.join(script_dir, "fastgdb_definitions")
    cmd = "readlink -f ~/.fastgdb/fastgdb"
    fastgdb_file = subprocess.check_output(cmd, shell=True).decode().strip()
    fastgdb_file = os.path.expanduser(fastgdb_file)
    for line in fileinput.input(fastgdb_file, inplace = 1):
        if line.startswith(key + " ="):
            line = key + " = " + cmd_str + "\n"
        sys.stdout.write(line)

def get_cmd(cmd_num, cmd_only=False):
    key = "g{}".format(cmd_num)
    # script_dir = os.path.dirname(os.path.realpath(__file__))
    # def_file = os.path.join(script_dir, "fastgdb_definitions")
    cmd = "readlink -f ~/.fastgdb/fastgdb_bp"
    return subprocess.getoutput('sed -n "/g{}/,/define/p" ~/.fastgdb/fastgdb_bp | head -n-1'.format(cmd_num))
    # fastgdb_file = subprocess.check_output(cmd, shell=True).decode().strip()
    # fastgdb_file = os.path.expanduser(fastgdb_file)
    # with open(fastgdb_file, "r") as f:
    #     lines = f.readlines()
    #     for line in lines:
    #         if line.startswith(key):
    #             if cmd_only:
    #                 return line.split("=")[-1].strip()
    #             else:
    #                 return line.strip()

def get_cmds():
    cmd = "readlink -f ~/.fastgdb/fastgdb_bp"
    fastgdb_file = subprocess.check_output(cmd, shell=True).decode().strip()
    fastgdb_file = os.path.expanduser(fastgdb_file)
    with open(fastgdb_file, "r") as f:
        lines = f.read()
        return lines.strip()

if 'gdb' in locals():
    NUM_FAST_CMDS = 10
    class FastCommand(gdb.Command):
        def __init__(self):
            super(FastCommand, self).__init__("fastcmd", gdb.COMMAND_USER)
            # fq_cmd = "define fq\n"
            gdb.execute("source ~/.fastgdb/fastgdb_bp")
            for i in range(0, NUM_FAST_CMDS):
                # fq_cmd += "f{}q\n".format(i)
                # TODO: convert these to an alias passing a command to fastcmd, e.g.
                # fastcmd print 1 or fastcmd execute 1
                # gdb.execute("alias f{0}. = fastcmd {0}".format(i))
                # gdb.execute("define g{0}\nfastcmd run {0}\nend".format(i))
                gdb.execute("define gv{0}\ngv {0}\nend".format(i))
                gdb.execute("define g{0}q\nfastcmd query {0}\nend".format(i))
                gdb.execute("define ga\nfastcmd query all\nend".format(i))
                gdb.execute("define gg\nfastcmd query 0-4\nend".format(i))
                gdb.execute("define G\nfastcmd query 5-9\nend".format(i))

                # gdb.execute("define f{0}q\n! sed -n '/^define f{0}/,/^#F{0}_INSERT_MARKER/".format(i) + "{//!p;}' ~/.gdbinit\nend")
                # gdb.execute("define f{0}q\n! sed -n '/^define f{0}/,/^#F{0}_INSERT_MARKER/".format(i) + "{//!p;}' ~/.gdbinit\nend")
                # gdb.execute("define f")
            # fq_cmd += "end"
            gdb.execute("define g\nfastcmd query default\nend")
            gdb.execute("""
define gv
if $argc >= 1
  set $target_num = $arg0
else
  set $target_num = -1
end
python
import os
target_num = gdb.convenience_variable("target_num")
if not (target_num and 0 <= target_num <= 9):
    with open(os.path.expanduser('~/.fastgdb/fastgdb_default_dest')) as f:
        target_num = int(f.read())
subprocess.run(f"vim -c '/g{target_num}' -c '/end' -c '.-1' ~/.fastgdb/fastgdb_bp", shell=True)
end
source ~/.fastgdb/fastgdb_bp
end
""")
            gdb.execute("""
define gdf
if $argc >= 1
  set $default_num = $arg0
end
python
default_num = gdb.convenience_variable("default_num")
if default_num and 0 <= default_num <= 9:
    subprocess.run("echo {} > ~/.fastgdb/fastgdb_default_dest".format(default_num), shell=True)
else:
    print("usage:   gdf [0-9]")
current_num = subprocess.getoutput("cat ~/.fastgdb/fastgdb_default_dest")
print("current: {}".format(current_num))
end
end
""")
            gdb.execute("alias g.=fastcmd")
            gdb.execute("define .b\nsource source ~/.fastgdb/fastgdb_bp\nend")
            # gdb.execute(fq_cmd)

        def invoke(self, args, from_tty):
            arglist = args.split()
            if len(arglist) == 2:
                cmd, param = arglist
            else:
                cmd = arglist[0]
                param = ' '.join(arglist[1:])
            if cmd == "set":
                cmd_num = param
                try:
                    gdb_cmds = input("Enter g{} command: ".format(cmd_num))
                    if gdb_cmds == "":
                        grep_cmd = "<(grep FASTGDB_QUEUE ~/.gdbinit | cut -d':' -f2 | sed 's/^[ \t]//')"
                        gdb_cmds = subprocess.check_output("tac {} ~/.gdb_history | fzf --no-sort".format(grep_cmd), shell=True, executable="/bin/bash").decode().strip()
                    save_cmd(cmd_num, gdb_cmds)
                except KeyboardInterrupt:
                    print("༼ つ ◕_◕ ༽つ yeet")
            elif cmd == "run":
                cmd_num = param
                gdb_cmds = get_cmd(cmd_num, cmd_only=True).split(";")
                gdb_cmds = [x.strip() for x in gdb_cmds]

                USE_MACRO=False
                if USE_MACRO:
                    macro = ""
                    for gdb_cmd in gdb_cmds:
                        macro += "{}\n".format(gdb_cmd)
                    macro = "define tmp\n" + macro + "end"
                    print(macro)
                    gdb.execute(macro)
                    gdb.execute("tmp")
                else:
                    for gdb_cmd in gdb_cmds:
                        print("fastgdb> {}".format(gdb_cmd))
                        ret = gdb.execute(gdb_cmd, to_string=True)
                        if ret != "":
                            print(ret)

            elif cmd == "query":
                if param == "all":
                    print(get_cmds())
                elif param == "default":
                    cmd_num_default = subprocess.getoutput("cat ~/.fastgdb/fastgdb_default_dest")
                    print(get_cmd(cmd_num_default))
                elif param.isnumeric():
                    cmd_num = param
                    print(get_cmd(cmd_num))
                elif "-" in param:
                    start, end = map(int, param.split("-"))
                    for i in range(start, end+1):
                        print(get_cmd(i))
                else:
                    print("error: invalid argument {}".format(param))

            elif cmd.isnumeric():
                save_cmd(cmd, param)

            elif arg == "?":
                pass

if __name__ == '__main__':
    import fileinput
    import os
    import subprocess
    import sys

    if len(sys.argv) < 3:
        FastCommand()
    else:
        key = sys.argv[1]
        new_cmd = ' '.join(sys.argv[2:])
        cmd = "readlink -f ~/.fastgdb/fastgdb"
        fastgdb_file = subprocess.check_output(cmd, shell=True).decode().strip()
        for line in fileinput.input(os.path.expanduser(fastgdb_file), inplace = 1):
            if line.startswith(key + " ="):
                line = key + " = " + new_cmd + "\n"
            sys.stdout.write(line)

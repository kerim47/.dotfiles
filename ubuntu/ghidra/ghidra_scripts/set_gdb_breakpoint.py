'''
set-gdb-breakpoint.py: Ghidra script for adding gdb breakpoints.

Adds a breakpoint for the current address in Ghidra to a macro in ~/.gdbinit. It is recommended to add a keybinding, e.g. Ctrl-Shift-B.

NOTE:
For this script to work, you need a macro in your ~/.gdbinit with the comment
#BREAKPOINT_INSERT_MARKER, like the following:

# fast breakpoints
define fb

end #BREAKPOINT_INSERT_MARKER


When in gdb, you can run "fb" to set the breakpoints you just added through
ghidra. You may also want the gdb macros at the bottom of this file or something
similar for setting PIE breakpoints.


#BP_TYPE,b:qemu-aarch64-static:nyanc
#REPWN,nka:gmul:qemu

#FASTGDB_QUEUE: b *0x401d08
'''
import fileinput
import os
import sys
import subprocess

breakpoint_type = subprocess.check_output("grep BP_TYPE ~/.gdbinit | cut -d',' -f2 | cut -d':' -f1", shell=True).rstrip().decode("utf-8")
breakpoint_cmd = "{} {}".format(breakpoint_type, "*" if breakpoint_type == "b" else "")
breakpoint_address = int(currentAddress.toString(), 16)
# If the binary has PIE enabled, subtract the load address
if int(getFirstData().address.toString(), 16) == 0x100000:
    breakpoint_address -= 0x100000
breakpoint_str = breakpoint_cmd + hex(breakpoint_address)
os.system("python3 -c 'import pyperclip; pyperclip.copy(\"{}\")'".format(breakpoint_str))
# os.system("tmux send-keys '{}{}' C-a right right right".format(gdot_str, breakpoint_str))
with open(os.path.expanduser("~/.fastgdb/fastgdb_default_dest"), "r") as f:
    ghidra_dest = f.read().strip()
    # print("ghidra_dest = {}".format(ghidra_dest))

print("Inserting '{}' into g{}".format(breakpoint_str, ghidra_dest))
# f = fileinput.FileInput(os.path.expanduser("~/.gdbinit"), inplace=True)
fastgdb_file = os.path.realpath(os.path.expanduser("~/.fastgdb/fastgdb_bp"))
# print("fastgdb_file = {}".format(fastgdb_file))
# print("ghidra_dest = [{}]".format(ghidra_dest))

next_slot = str(int(ghidra_dest) + 1)
try:
    linum = int(subprocess.check_output("cat ~/.fastgdb/fastgdb_bp | grep -B1000 -n 'define g" + next_slot + "' | grep end | tail -n1 | cut -f1 -d-", shell=True).rstrip().decode("utf-8"))
except:
    print("Unable to find insertion line number")
    sys.exit()

lines = []
with open(fastgdb_file, "r") as f:
    lines = f.readlines()
    lines.insert(linum-1, breakpoint_str + "\n")
with open(fastgdb_file, "w") as f:
    f.writelines(lines)

import os
insts = currentProgram.getListing().getCodeUnits(ghidra.program.model.address.AddressSet(currentSelection.minAddress, currentSelection.maxAddress), True)
outstring = currentSelection.minAddress.toString() + ": " + '; '.join([ inst.toString() for inst in insts ])
print(outstring)
os.system("python3 -c 'import pyperclip; pyperclip.copy(\"{}\")'".format(outstring))

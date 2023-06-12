#!/usr/bin/env python3

current_inst = getInstructionAt(currentAddress)
addr = currentAddress

while True:
    current_inst = getInstructionAt(addr)
    if current_inst == None:
        current_data = getDataAt(addr)
        if current_data != None:
            addr = addr.add(current_data.length)
        # elif getSymbolAt(addr) != None:
        #     # Pointer
        #     addr = addr.add(4)
        elif getByte(addr) == 0:
            # Skip over zero bytes
            addr = addr.add(1)
        else:
            print("Found undefined instruction at %s" % addr)
            setCurrentLocation(addr)
            break
    else:
        addr = addr.add(current_inst.length)

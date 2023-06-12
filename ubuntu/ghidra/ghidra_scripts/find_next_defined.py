#!/usr/bin/env python3

next_inst = getInstructionAfter(currentAddress)
new_addr = next_inst.getAddress()
print("Found defined instruction at %s" % new_addr.toString())
setCurrentLocation(new_addr)

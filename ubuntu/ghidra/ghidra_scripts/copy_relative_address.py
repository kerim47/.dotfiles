import os

cur_address = int(currentAddress.toString(), 16)
# if int(getFirstData().address.toString(), 16) == 0x100000:
cur_address -= int(getFirstData().address.toString(), 16)
print("Copied {} to clipboard".format(hex(cur_address)))
os.system("echo -n {} | xclip -sel clip".format(hex(cur_address)))

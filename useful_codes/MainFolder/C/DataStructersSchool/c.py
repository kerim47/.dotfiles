import subprocess

# subprocess modülü kullanarak C programını başlatın
process = subprocess.Popen(['./pyc'], stdout=subprocess.PIPE)

# stdout'dan çıktıyı oku
while True:
    output = process.stdout.readline()
    if output == '' and process.poll() is not None:
        break
    if output:
        print(output.strip().decode())

# process nesnesini bekle ve sonlandır
process.wait()

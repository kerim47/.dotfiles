<details> <summary>Wsl Uzerinden Windows Kullanici Dizinini Goruntuleme</summary>
`wslpath "$(wslvar USERPROFILE)"`

Bu kod, Windows Subsystem for Linux (WSL) üzerinde çalıştırıldığında Windows kullanıcı dizinini temsil eden `$USERPROFILE` ortam değişkenini WSL yoluna dönüştürmek için `wslpath` komutunu kullanır. Bu komut, Windows tarafındaki kullanıcı dizinini WSL içinde kullanılabilir bir şekle dönüştürür.

`sudo apt install wslu`

Bu kod, `wslu` paketinin WSL üzerinde kurulmasını sağlar. `wslu`, WSL kullanıcılarının Windows tarafından sağlanan bazı ek araçlara erişmelerini kolaylaştıran bir yardımcı program koleksiyonudur. Bu komutu çalıştırarak `wslu` paketini kurabilirsiniz.

`export WINHOME=$(wslpath "$(wslvar USERPROFILE)")`

</details>

-- Lua:
-- For dark theme (neovim's default)
-- vim.o.background = 'dark'
-- For light theme
-- vim.o.background = 'light'

-- local c = require('vscode.colors').get_colors()
--vim.cmd("set colorscheme vscode")
-- Lua:
-- For dark theme (neovim's default)
vim.o.background = 'dark'
-- For light theme
-- vim.o.background = 'light'
-- İstediğiniz modülü yüklemek için bir fonksiyon tanımlayın
local function loadVscode()
  require('vscode').load('dark')
end

-- Modülü tekrar yüklemek için bir kontrol tablosu oluşturun
local loadedModules = {}

-- Modülü yükleme işlemini gerçekleştiren işlev
local function requireWithReload(moduleName)
  if not loadedModules[moduleName] then
    loadedModules[moduleName] = true
    require(moduleName)
  end
end

-- Modülü tekrar yükle
requireWithReload('vscode')

-- Başka bir dosyada veya oturumda modülü tekrar yükle
loadVscode()


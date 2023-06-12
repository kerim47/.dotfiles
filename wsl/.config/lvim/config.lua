require("user.plugins")
require("user.general")
require("user.keymaps")
require("user.telescope")
require("user.nvim-options")
require("user.nvim-scrool")
require("user.nvim-noice")
require("user.formatOnSave")
require("user.autocommands")
require("user.copilot")
require("user.ufo")
require("user.nui")
require("user.preview")
require("user.nvim-noice")
require("user.nvim-multiple-cursor")
require("user.magma")
require("user.jupyter")
require("user.which_keymap")
require("user.toggle_term")
require("user.icons")
require("user.bookmark")
require("user.todo_comments")
require("user.symbols_outline")
require("user.sniprun")
require("user.tabnine")
require("user.jupynium")
require("user.markdown")
require("user.functions")
require("user.autohotkey")
require("user.lua-snip")


vim.api.nvim_command('au BufRead,BufNewFile *.txt set filetype=markdown')
function RandomColor()
  local colors = { 'Red', 'Blue', 'Green', 'Yellow' } -- Rastgele renklerin listesi
  local randomIndex = math.random(1, #colors) -- Rastgele bir renk seçin
  return colors[randomIndex]
end

vim.api.nvim_command('syntax match TxtParagraph "^.*$" containedin=ALL')

-- TxtParagraph için renklendirme ayarlarını rastgele renklere ayarlayın
vim.api.nvim_command('autocmd ColorScheme * highlight TxtParagraph ctermfg=' .. RandomColor() .. ' ctermbg=NONE guifg=' .. RandomColor() .. ' guibg=NONE')


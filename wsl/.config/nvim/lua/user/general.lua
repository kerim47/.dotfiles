--vim.cmd [[autocmd CursorMoved * if foldlevel('.') > 0 | silent! exe "norm! zv" | endif]]
--vim.cmd [[autocmd CursorMoved * if foldlevel('.') == 0 | silent! exe "norm! zM" | endif]]
-- vim.cmd [[autocmd TermOpen * lua vim.api.nvim_echo({{'Hoş geldiniz', 'Normal'}}, true, {})]]
-- fzf is just an example
vim.cmd("autocmd FileType bash setlocal nonumber")

local o=vim.o
local g=vim.g

--vim.cmd("colorscheme vscode")
o.foldcolumn = '1'
o.fillchars = [[eob: ,fold: ,foldopen:🡻,foldsep: ,foldclose:🡺]]
vim.cmd([[autocmd VimEnter * lua vim.b.copilot_enabled = true]])
g.loaded_perl_provider = 0
vim.opt.shell="/bin/bash"

function file_type()
  vim.cmd("call jukit#splits#output_and_history()")
  vim.cmd("call jukit#layouts#set_layout()")
end
-- Define a function to bind the key mappings if the terminal is kitty
function setup_kitty_mappings()
  local filetype = vim.fn.expand('%:e')
  if filetype == 'ipynb' then
    vim.api.nvim_set_keymap("n", "<leader>oj", "<cmd>lua file_type()<CR>", { noremap = true })
  end
end

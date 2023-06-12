local leader = " "
-- noremap ve silent true olarak bir keymap tanımla
local function keymap(mode, lhs, rhs, opts)
  opts = opts or {noremap = true, silent = true}
  vim.api.nvim_set_keymap(mode, lhs, rhs, opts)
end

keymap("n", "<leader>n", ":ASToggle<CR>")
keymap("n", "<leader>n", ":ASToggle<CR>")

-- Ctrl 
keymap("n", "<c-s>", ":w<cr>")
keymap('n', '<c-j>', 'dd')

-- shift
keymap("n", "<s-h>", "0")
keymap("n", "<s-l>", "$")

-- tab
keymap("n", "<tab>", ":bnext<cr>")
keymap("n", "<s-tab>", ":bprevious<cr>")

-- leader
keymap("n", "<leader>-", ":TagbarToggle<cr>")
keymap("n", "<leader>wh", "<C-w>h")
keymap("n", "<leader>wl", "<C-w>l")
keymap("n", "<leader>a", "gg0<s-v>G$")
keymap("n", "<leader>t", ":BufferKill<cr>")

keymap("n", "<M-h>", ":vertical resize -2<cr>")
keymap("n", "<M-l>", ":vertical resize +2<cr>")
keymap('n', '<cr>', 'v}')

keymap('n', 'ds', ':HopAnywhere<cr>')
-- insert mode keymapping
-- Ctrl
keymap("i", "<c-w>", "<esc>:wq!<cr>")
keymap("i", "<c-s>", "<esc>:w<cr>i")

-- visual mode keymapping
keymap("v", "<s-h>", "0")
keymap("v", "<s-l>", "$")
keymap('v', '<C-c>', ':w! ~/.vimbuffer | !cat ~/.vimbuffer | clip.exe<CR>')


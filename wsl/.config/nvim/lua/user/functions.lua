local M = {}
-- C programlama dili i├ğin kullanilmistir
function M.comment_selected_text(chr)
  local lang_chr = chr or "*"
  -- Get the current visual selection
  local _, start_row, start_col, _ = unpack(vim.fn.getpos("'<"))
  local _, end_row, end_col, _ = unpack(vim.fn.getpos("'>"))

  -- Check if the selection is already commented or not
  local is_commented = true
  for i = start_row, end_row do
    local line = vim.fn.getline(i)
    if not line:find("^%s*/%*%s*" .. lang_chr) then
      is_commented = false
      break
    end
  end

  -- Comment or uncomment the selection based on the current state
  if is_commented then
    -- Remove the comments
    vim.api.nvim_buf_set_lines(0, start_row-1, start_row, false, {})
    vim.api.nvim_buf_set_lines(0, end_row-1, end_row, false, {})
  else
    -- Add the comments
    vim.api.nvim_buf_set_lines(0, start_row-1, start_row-1, false, {"/*"})
    for i = start_row, end_row do
      local line = vim.fn.getline(i)
      vim.fn.setline(i, " " .. lang_chr .. " " .. line)
    end
    vim.api.nvim_buf_set_lines(0, end_row+1, end_row+1, false, {" */"})
  end
end

function M.comment_text(chr)
  if vim.bo.filetype == "c" then
    M.comment_selected_text(chr)
  end
end

function M.c_command()
  -- C code execute
  local dosya_yolu = vim.api.nvim_buf_get_name(0)
  -- Uzantıyı ayır
  local uzanti = string.match(dosya_yolu, "%.([^%.]+)$")
  if uzanti == 'c' then
    vim.keymap.set( 'n', '<F4>', ':w<CR>:!gcc % -o output && ./output<CR>')
    vim.keymap.set( 'v', '<F4>', ':w<CR>:!gcc % -o output && ./output<CR>')
    vim.keymap.set( 'n', '<leader>m', ':w<CR>:TermExec cmd="gcc % -o output && ./output"<CR>')
    vim.keymap.set( 'v', '<leader>m', ':w<CR>:TermExec cmd="gcc % -o output && ./output"<CR>')
  end
end

return {
  comment_text = M.comment_text,
  c_setup_command = M.c_command,
}


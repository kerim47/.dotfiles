# Created by Zap installer
[ -f "${XDG_DATA_HOME:-$HOME/.local/share}/zap/zap.zsh" ] && source "${XDG_DATA_HOME:-$HOME/.local/share}/zap/zap.zsh"
plug "zsh-users/zsh-autosuggestions"
plug "zap-zsh/supercharge"
plug "zap-zsh/zap-prompt"
plug "zsh-users/zsh-syntax-highlighting"
# --- My Added Plugins ---

plug "zap-zsh/vim"
plug "zap-zsh/exa"

source ~/.dotfiles_ubuntu/fzf-tab/fzf-tab.plugin.zsh
source ~/.dotfiles_ubuntu/zsh-users/alias.sh

plugins=(
  you-should-use
  )
# Load and initialise completion system
autoload -Uz compinit
compinit

export NVM_DIR="$HOME/.nvm"
[ -s "$NVM_DIR/nvm.sh" ] && \. "$NVM_DIR/nvm.sh"  # This loads nvm
[ -s "$NVM_DIR/bash_completion" ] && \. "$NVM_DIR/bash_completion"  # This loads nvm bash_completion


source "$HOME/.cargo/env"
fpath+=${ZDOTDIR:-~}/.zsh_functions
# eval "$(/home/linuxbrew/.linuxbrew/bin/brew shellenv)"
export PATH="$HOME/miniconda3/bin:$PATH"  # commented out by conda initialize

# >>> conda initialize >>>
# !! Contents within this block are managed by 'conda init' !!
__conda_setup="$('/home/kerim/miniconda3/bin/conda' 'shell.zsh' 'hook' 2> /dev/null)"
if [ $? -eq 0 ]; then
    eval "$__conda_setup"
else
    if [ -f "/home/kerim/miniconda3/etc/profile.d/conda.sh" ]; then
        . "/home/kerim/miniconda3/etc/profile.d/conda.sh"
    else
        export PATH="/home/kerim/miniconda3/bin:$PATH"
    fi
fi
unset __conda_setup
# <<< conda initialize <<<

run() { 
  nohup "$@" & 
}

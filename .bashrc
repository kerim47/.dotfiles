# if command -v kitty &> /dev/null && [[ -n "$DISPLAY" ]]; then
#     if ! pgrep -x "kitty" > /dev/null; then
#       jupi
#     fi
# fi

if command -v tmux &> /dev/null && [ -n "$PS1" ] && [[ ! "$TERM" =~ screen ]] && [[ ! "$TERM" =~ tmux ]] && [ -z "$TMUX" ]; then
  exec tmux
fi
eval "$(oh-my-posh --init --shell bash --config ~/.poshthemes/takuya.omp.json)"
alias install='echo 1 | sudo -S apt-get install'
alias update='echo 1 | sudo -S apt-get update'
alias upgrade='echo 1 | sudo -S apt-get upgrade'
alias ..='cd ..'
alias ...='cd ../..'
alias ....='cd ../../..'
alias C='cd ~/MainFolder/ProgrammingCodes/C/'
alias l='lvim'
alias src='source ~/.bashrc'
alias jupi="kitty --listen-on=unix:@"$(date +%s%N)" -o allow_remote_control=yes --start-as fullscreen"
HELIX_RUNTIME=$HOME/helix/runtime
bind 'set show-all-if-ambiguous on'
bind 'TAB:menu-complete'
bind '"\e[A": history-search-backward'
bind '"\e[B": history-search-forward'
HELIX_RUNTIME=$HOME/helix/runtime/
# source <(kitty + complete setup bash)

export PATH=$PATH:/usr/local/go/bin

export OPENAI_API_KEY="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"
export NVM_DIR="$HOME/.nvm"
[ -s "$NVM_DIR/nvm.sh" ] && \. "$NVM_DIR/nvm.sh"  # This loads nvm
[ -s "$NVM_DIR/bash_completion" ] && \. "$NVM_DIR/bash_completion"  # This loads nvm bash_completion

#source line added
export NVM_DIR="$([ -z "${XDG_CONFIG_HOME-}" ] && printf %s "${HOME}/.nvm" || printf %s "${XDG_CONFIG_HOME}/nvm")"
[ -s "$NVM_DIR/nvm.sh" ] && \. "$NVM_DIR/nvm.sh" # This loads nvm
# . "$HOME/.cargo/env"

# >>> conda initialize >>>
# !! Contents within this block are managed by 'conda init' !!
__conda_setup="$('$HOME/anaconda3/bin/conda' 'shell.bash' 'hook' 2> /dev/null)"
if [ $? -eq 0 ]; then
    eval "$__conda_setup"
else
    if [ -f "$HOME/anaconda3/etc/profile.d/conda.sh" ]; then
        . "$HOME/anaconda3/etc/profile.d/conda.sh"
    else
        export PATH="$HOME/anaconda3/bin:$PATH"
    fi
fi
unset __conda_setup
# <<< conda initialize <<<

# . /opt/conda/etc/profile.d/conda.sh  # commented out by conda initialize
# Set the default terminal to xterm-256color
export TERM=xterm-256color

# Setup cdg (for fzf) function
# ------------------
unalias cdg 2> /dev/null
cdg() {
  # get the autopath directory list with the following command:
  # j -s | grep "^data:" | cut -d ' ' -f 2
  local autojump_list='$HOME/MainFolder/autojump.txt'
  local dest_dir=$(cat $autojump_list | cut -d$'\t' -f 2 | fzf )
  if [[ $dest_dir != '' ]]; then
    if [[ -d "$dest_dir" ]]; then
      cd "$dest_dir"
    else
      dir=$(dirname "$dest_dir")
      cd "$dir"
    fi
    lvim "$dest_dir"
  fi
}
export -f cdg > /dev/null

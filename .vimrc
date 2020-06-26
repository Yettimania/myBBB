let mapleader =","

" colorscheme koehler
colorscheme koehler

" Fast saving
nmap <leader>w :w!<cr>

syntax enable
" show line numbers
" set number
set rnu

" needed for light line
set laststatus=2

" set tabs to have 4 spaces
set ts=4

" indent when moving to the next line while writing code
set ai "Auto indent
set si "Smart indent
set wrap "Wrap Lines

" expand tabs into spaces
set expandtab

" when using the >> or << commands, shift lines by 4 spaces
set shiftwidth=4

" show a visual line under the cursor's current line
set cursorline
hi CursorLine ctermfg=black ctermbg=darkgray cterm=bold
" hi Cursor ctermbg=15 ctermfg=8

" show the matching part of the pair of [] {} and ()
set showmatch

" Set 7 lines to the cursor - when moving vertically using j/k
set so=7

" Toggle mapping for NERDTree
map <C-t> :NERDTreeToggle<CR>

" This is basics for vim surround
" It's easiest to explain with examples. Press cs"' inside
" "Hello world!"
" to change it to
" 'Hello world!'

 "____        _                  _
"/ ___| _ __ (_)_ __  _ __   ___| |_ ___
"\___ \| '_ \| | '_ \| '_ \ / _ \ __/ __|
 "___) | | | | | |_) | |_) |  __/ |_\__ \
"|____/|_| |_|_| .__/| .__/ \___|\__|___/
              "|_|   |_|


" Run Julia Files
    nnoremap <C-j> <esc>:w<enter>:! julia %:p<enter>
    inoremap <C-j> <esc>:w<enter>:! julia %:p<enter>

" Commenting in C
map <C-c> :s/^/\/\//<CR>
map <C-u> :s/^\/\///<CR>

" Make and compile file 
map <C-m> :!make<enter>:!%:r<enter>





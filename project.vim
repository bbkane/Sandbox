" Load this with command LoadProjectVimrc

set makeprg=cd\ ../build_mac\ &&\ make

" assumes the current file is the name of the executable
map <F5> :w<CR> :make<CR> :!../bin/%:r<CR>

command! EditCMakeFile vsplit ../CMakeLists.txt

command! CMake !cd ../build && cmake ..


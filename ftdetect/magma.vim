" Detect Magma files
" .magma files are always Magma
autocmd BufRead,BufNewFile *.magma setfiletype magma

" .m files need heuristic detection (conflicts with MATLAB/Objective-C)
autocmd BufRead,BufNewFile *.m call s:DetectMagma()

function! s:DetectMagma()
    let n = 1
    while n <= min([line("$"), 30])
        let line = getline(n)
        if line =~# '^\s*\(freeze\|intrinsic\|end function\|end procedure\|end intrinsic\)'
            setfiletype magma
            return
        endif
        let n += 1
    endwhile
endfunction

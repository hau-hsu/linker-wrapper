%rename invoke_as old_invoke_as
%rename linker old_linker

*invoke_as:
%{!fwpa*:   %{fcompare-debug=*|fdump-final-insns=*:%:compare-debug-dump-opt()} %{!S:-o %|.s |  wrap-symbols %m.s }  %{!S:-o %|.s |  as %(asm_options) - %A }  }

*linker:
ld-wrapper

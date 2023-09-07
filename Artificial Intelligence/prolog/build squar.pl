squar(0, _).
squar(N, Ch) :-
    N > 0,
    print_row(N, Ch),
    NextN is N-1,
    squar(NextN, Ch).
print_row(0, _):-
    nl.
print_row(N, Ch):-
    N>0,
    write(Ch),
    write(' '),
    Next is N-1,
    print_row(Next, Ch).

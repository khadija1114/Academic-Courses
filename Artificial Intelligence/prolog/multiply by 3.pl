multiply3([],_, []).
multiply3([_|T], L, R):-
    multiply3(T, L, Rt),
    append(L, Rt, R).

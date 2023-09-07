plus([], X, X).
plus([x|T], L, [x|R]) :-
    plus(T, L, R).

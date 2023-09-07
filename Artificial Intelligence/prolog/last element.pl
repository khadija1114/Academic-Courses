last1(X, [X]).
last1(X, [_| T]):-
    last1(X, T).

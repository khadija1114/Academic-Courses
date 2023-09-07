membership(H, [H|_]).
membership(H, [_|T]) :-
    membership(H, T).

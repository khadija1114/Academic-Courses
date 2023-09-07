successor([], [x]).
successor([x|T], [x|L]) :-
    successor(T, L).

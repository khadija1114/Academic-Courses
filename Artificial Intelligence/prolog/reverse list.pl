reverse_list([], []).
reverse_list([H|T], R):-
    reverse_list(T, Rt),
    append(Rt, [H], R).

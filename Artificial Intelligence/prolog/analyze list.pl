analyze_list([]) :-
    write('empty list.'),nl.
analyze_list([H|T]) :-
    write('Head: '), write(H), nl,
    write('Tail: '), write(T), nl.
analyze_list(_) :-
    write('No'), nl,
    fail.

concat_list([], List, List).
concat_list([H|T], List2, [H|List3]):-
    concat_list(T, List2, List3).

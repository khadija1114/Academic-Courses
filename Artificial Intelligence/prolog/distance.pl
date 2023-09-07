distance((X1, Y1), (X2, Y2), D) :-
    Dx is  X2-X1,
    Dy is Y2-Y1,
    D is sqrt(Dx*Dx + Dy*Dy).

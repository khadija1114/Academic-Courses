female(mary).
female(sandra).
female(juliet).
female(lisa).
male(peter).
male(paul).
male(dick).
male(bob).
male(harry).
parent(bob,lisa).
parent(bob,paul).
parent(bob,mary).
parent(juliet,lisa).
parent(juliet,paul).
parent(juliet,mary).
parent(peter,harry).
parent(lisa,harry).
parent(mary,dick).
parent(mary,sandra).

father(F,X):- parent(F,X),male(F).
mother(M,X):-parent(M,X),female(M).
sibling(X,Y):-parent(P,X),parent(P,Y),X\=Y.
sister(X,Y):-sibling(X,Y),female(Y).
grandmother(G,X):-parent(G,P),parent(P,X),female(G).
cousin(X,Y):-parent(P,X),parent(Q,Y),sibling(P,Q).

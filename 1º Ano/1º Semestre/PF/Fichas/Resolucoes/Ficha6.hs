module Ficha6 where



data BTree a = Empty
             | Node a (BTree a) (BTree a)
             deriving Show


t :: BTree Int
t = Node 7 (Node 3 Empty
                   (Node 5 Empty Empty))
           (Node 78 (Node 8 Empty Empty)
           Empty)

altura :: BTree a -> Int
altura Empty      = 0
altura (Node x l r) = 1 + max (altura l) (altura r)


contaNodos :: BTree a -> Int
contaNodos Empty = 0
contaNodos (Node x l r) = 1 + contaNodos l + contaNodos r



folhas :: BTree a -> Int
folhas Empty = 0
folhas (Node x Empty Empty) = 1
folhas (Node x l r) = folhas l + folhas r



prune :: BTree a -> Int -> BTree a
prune _ 0 = Empty
prune Empty _ = Empty
prune (Node x l r) n = (Node x l' r') 
                       where l' = prune l (n - 1)
                             r' = prune r (n - 1)




path :: [Bool] -> BTree a -> [a]
path [] (Node x _ _) = [x]
path (b:bs) (Node x l r) | b         = x : path bs r
                         | otherwise = x : path bs l




zipWithBT :: (a -> b -> c) -> BTree a -> BTree b -> BTree c
zipWithBT f (Node x1 l1 r1) (Node x2 l2 r2) = (Node (f x1 x2) l r)
                                                where l = zipWithBT f l1 l2
                                                      r = zipWithBT f r1 r2
zipWithBT _ _ _ = Empty



unzipBT :: BTree (a,b,c) -> (BTree a, BTree b, BTree c)
unzipBT Empty = (Empty, Empty, Empty)
unzipBT (Node (a,b,c) l r) = (Node a l1 r1, Node b l2 r2, Node c l3 r3)
                           where (l1, l2, l3) = unzipBT l
                                 (r1, r2, r3) = unzipBT r




minimo :: Ord a => BTree a -> a
minimo (Node a Empty _) = a
minimo (Node a l r) = minimo l



semMinimo :: Ord a => BTree a -> BTree a
semMinimo (Node a Empty r) = r
semMinimo (Node a l r) = (Node a (semMinimo l) r)



minSmin :: Ord a => BTree a -> (a,BTree a)
minSmin (Node a Empty Empty) = (a, Empty)
minSmin (Node a l r) = (m, Node a bt r)
                       where (m, bt) = minSmin l


remove :: Ord a => a -> BTree a -> BTree a
remove a Empty = Empty
remove a (Node x l r) | x == a    = removed
                      | x > a     = (Node x (remove a l) r)
                      | otherwise = (Node x l (remove a r))
                      where removed = case r of
                                            Empty -> Empty
                                            _    -> (Node x1 l r1)

                            (x1,r1) = minSmin r




type Aluno = (Numero,Nome,Regime,Classificacao)
type Numero = Int
type Nome = String
data Regime = ORD | TE | MEL  deriving Show
data Classificacao = Aprov Int| Rep| Faltou
                     deriving Show

type Turma = BTree Aluno  --  ́arvore binaria de procura (ordenada por numero)


inscNum :: Numero -> Turma -> Bool
inscNum _ Empty = False
inscNum no (Node (x, _, _, _) l r) | no == x   = True
                        | no < x    = inscNum no l
                        | otherwise = inscNum no r



inscNome :: Nome -> Turma -> Bool
inscNome _ Empty = False
inscNome str (Node (_, nm, _, _) l r) = (nm == str) || inscNome str l || inscNome str r
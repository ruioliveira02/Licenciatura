module Ficha7 where

import Ficha6


data ExpInt = Const Int
            | Simetrico ExpInt
            | Mais ExpInt ExpInt
            | Menos ExpInt ExpInt
            | Mult ExpInt ExpInt
            deriving Show



calcula :: ExpInt -> Int
calcula (Const x)     = x
calcula (Simetrico x) = -1 * calcula x
calcula (Mais l r)    = calcula l + calcula r
calcula (Menos l r)   = calcula l - calcula r
calcula (Mult l r)    = calcula l * calcula r



infixa :: ExpInt -> String
infixa (Const x)     = (show x)
infixa (Simetrico x) = "(-" ++ (infixa x) ++ ")"
infixa (Mais l r)    = "(" ++ (infixa l) ++ " + " ++ (infixa r) ++ ")"
infixa (Menos l r)   = "(" ++ (infixa l) ++ " - " ++ (infixa r) ++ ")"
infixa (Mult l r)    = "(" ++ (infixa l) ++ " * " ++ (infixa r) ++ ")"


posfixa :: ExpInt -> String
posfixa x = init (posfixa' x)


posfixa' :: ExpInt -> String
posfixa' (Const x)     = (show x) ++ " "
posfixa' (Simetrico x) = posfixa' x ++ "- "
posfixa' (Mais l r)    = posfixa' l ++ posfixa' r ++ "+ "
posfixa' (Menos l r)   = posfixa' l ++ posfixa' r ++ "- "
posfixa' (Mult l r)    = posfixa' l ++ posfixa' r ++ "* "





data RTree a = R a [RTree a]
             deriving Show




soma :: Num a => RTree a -> a
soma (R x rem) = x + sum (map soma rem)


altura' :: RTree a -> Int
altura' (R _ []) = 1
altura' (R _ rem) = 1 + maximum (map altura' rem)


prune' :: Int -> RTree a -> RTree a
prune' 1 (R a rem) = (R a [])
prune' lvl (R a rem) = (R a (map (prune' (lvl - 1)) rem))



mirror :: RTree a -> RTree a
mirror (R a []) = (R a [])
mirror (R a rem) = (R a (reverse (map mirror rem)))


postorder :: RTree a -> [a]
postorder (R a []) = [a]
postorder (R a rem) = concat (map postorder rem) ++ [a]



data LTree a = Tip a
             | Fork (LTree a) (LTree a)
             deriving Show


lt = Fork
        (Fork 
             (Tip 5) (Tip 2))
        (Fork
             (Fork (Tip 2) (Tip 3)) (Tip 0))
            

ltSum :: Num a => LTree a -> a
ltSum (Tip a) = a
ltSum (Fork l r) = ltSum l + ltSum r


listaLT :: LTree a -> [a]
listaLT (Tip a) = [a]
listaLT (Fork l r) = listaLT l ++ listaLT r


ltHeight :: LTree a -> Int
ltHeight (Tip _) = 1
ltHeight (Fork l r) = 1 + maximum [ltHeight l, ltHeight r]



data FTree a b = Leaf b
               | No a (FTree a b) (FTree a b)
               deriving Show






splitFTree :: FTree a b -> (BTree a, LTree b)
splitFTree (Leaf b) = (Empty, Tip b)
splitFTree (No a l r) = (Node a l1 r1, Fork l2 r2)
                      where (l1, l2) = splitFTree l
                            (r1, r2) = splitFTree r




bt = (Node 5 (Node 3 Empty Empty) (Node 6 (Node 7 Empty Empty) Empty))

ft = (No 5 (No 2 (Leaf 3) (Leaf 4)) (No 14 (Leaf 4) (Leaf 20)))


joinTrees :: BTree a -> LTree b -> Maybe (FTree a b)
joinTrees Empty (Tip b) = Just (Leaf b)
joinTrees (Node a l r) (Fork l1 r1) = case x1 of 
                                           Nothing  -> Nothing
                                           Just x11 -> case x2 of
                                                            Nothing  -> Nothing
                                                            Just x22 -> Just (No a x11 x22)
                                    where x1 = (joinTrees l l1) 
                                          x2 = (joinTrees r r1)
joinTrees _ _ = Nothing

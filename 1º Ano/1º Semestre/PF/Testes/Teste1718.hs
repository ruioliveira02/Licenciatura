module Teste1819 where

import System.Random

import Data.List



insert' :: Ord a => a -> [a] -> [a]
insert' a [] = [a]
insert' a (h:t) | a < h     = (a:h:t)
               | otherwise = (h:(insert' a t))



catMaybes' :: [Maybe a] -> [a]
catMaybes' [] = []
catMaybes' (Nothing:t) = catMaybes' t
catMaybes' ((Just a):t) = a : (catMaybes' t)




data Exp a = Const a 
           | Var   String 
           | Mais (Exp a) (Exp a)
           | Mult (Exp a) (Exp a)

instance (Show a) => Show (Exp a) where
    show = showExp




showExp :: Show a => Exp a -> String
showExp (Const a)  = show a
showExp (Var str)  = str
showExp (Mais l r) = "(" ++ (showExp l) ++ "+" ++ (showExp r) ++ ")"
showExp (Mult l r) = "(" ++ (showExp l) ++ "*" ++ (showExp r) ++ ")"







sortOn' :: Ord b => (a -> b) -> [a] -> [a]
sortOn' _ [] = []
sortOn' f (h:t) = (sortOn' f [y | y <- t, (f y) <= (f h)]) ++ [h] ++ (sortOn' f [y | y <- t, (f y) > (f h)])












amplitude :: [Int] -> Int
amplitude [] = 0
amplitude lista = mx - mn
                where (mn,mx) = minmax lista


minmax :: [Int] -> (Int,Int)
minmax [x] = (x,x)
minmax (x:t) | x > mx      = (mn, x)
             | x < mn      = (x,mx)
             | otherwise   = (mn,mx)
             where (mn,mx) = minmax t



parte :: [Int] -> ([Int],[Int])
parte lista = splitAt x sorted
            where sorted = sort lista
                  (x,_)  = parteSorted sorted 1 (head sorted) (last sorted)



parteSorted :: [Int] -> Int -> Int -> Int -> (Int,Int)
parteSorted [x,y] i mn mx = (i, (mx-y) + (x-mn))
parteSorted (x:y:t) i mn mx | custo < b = (i, custo)
                            | otherwise = (a,b)
                            where custo = (x -mn) + (mx - y)
                                  (a,b) = parteSorted (y:t) (i+1) mn mx










data Imagem = Quadrado Int
            | Mover (Int,Int) Imagem
            | Juntar [Imagem]
            deriving Show


conta :: Imagem -> Int
conta (Quadrado _)   = 1
conta (Mover _ img)  = conta img
conta (Juntar lista) = sum (map conta lista)





apaga :: Imagem -> IO Imagem
apaga img = do
    let no = conta img
    i  <- randomRIO (0,no-1)

    return (fst (apagaImg i img))



apagaImg :: Int -> Imagem -> (Imagem, Int)
apagaImg 0 (Quadrado _) = (Juntar [],-1)
apagaImg n img | n < 0  = (img,-1)
apagaImg n (Mover _ img) = apagaImg n img
apagaImg n (Quadrado i) = (Quadrado i, n-1)
apagaImg n (Juntar [])  = (Juntar [], n)
apagaImg n (Juntar (h:t)) = (novaImagem,d)
                          where (a,b) = apagaImg n h
                                (Juntar c,d) = apagaImg b (Juntar t)
                                novaImagem = Juntar (a:c) 
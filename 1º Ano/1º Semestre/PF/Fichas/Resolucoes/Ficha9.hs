module Ficha9 where


import System.Random
import Data.Char
import System.IO.Unsafe

randomShuffle :: Int -> [a] -> [a]
randomShuffle _ [] = []
randomShuffle size (x:xs) = first ++ [x] ++ second
                     where randNum = unsafePerformIO $ randomRIO (0,size)
                           (first, second) = splitAt randNum (randomShuffle (size - 1) xs)


showNumbers :: [Int] -> IO ()
showNumbers [] = return ()
showNumbers (x:xs) = do
    getChar
    putStrLn (show x)
    showNumbers xs



bingo :: IO ()
bingo = showNumbers (randomShuffle 90 [1..90])



compare' :: String -> String -> String -> (Int,Int)
compare' [] [] _  = (0,0)
compare' (c:cs) (t:ts) og | c == t    = (1+a,b + 1)
                          | elem t og = (a, b + 1)
                          | otherwise = (a,b)
                          where (a,b) = compare' cs ts og


masterMind' :: String -> IO ()
masterMind' code = do
    tested <- getLine
    let (correct', wrong') = compare' code tested code
    let (correct, wrong) = (correct, wrong - correct)
    putStrLn ("Numero de algarismos com o valor correto na posicao certa: " ++ (show correct))
    putStrLn ("Numero de algarismos com o valor correto na posicao errada: " ++ (show wrong))

    if (correct == 4) then
        putStrLn "ACERTOU!!!!!!" >> (return ())
    else
        masterMind' code


generateCode :: IO Int
generateCode = do
    (randomRIO (1000,9000))

masterMind :: IO ()
masterMind = do
    code <- generateCode
    masterMind' (show code)



data Aposta = Ap [Int] (Int,Int)


temRepetidos :: [Int] -> Bool
temRepetidos [] = False
temRepetidos (x:xs) | elem x xs = True
                    | otherwise = temRepetidos xs

valida :: Aposta -> Bool
valida (Ap list (x,y)) = (x <= 9 && x >= 0) && (y <= 9 && y >= 0) && (y /= x) && (length list == 5) && (not (temRepetidos list))


comuns :: Aposta -> Aposta -> (Int, Int)
comuns (Ap list (e1,e2)) (Ap [] (e3,e4)) | e3 == e1  = if (e4 == e2) then (0,2) else (0,1)
                                         | e3 == e2  = if (e4 == e1) then (0,2) else (0,1)
                                         | otherwise = if (e4 == e2 || e4 == e1) then (0,1) else (0,0)
comuns (Ap list (e1,e2)) (Ap (x:t) (e3,e4)) | elem x list = (1 + a, b)
                                            | otherwise   = (a,b)
                                               where (a,b) = comuns (Ap list (e1,e2)) (Ap t (e3, e4))


equal :: Aposta -> Aposta -> Bool
equal a1 a2 = comuns a1 a2 == (5,2)


premio :: Aposta -> Aposta -> Maybe Int
premio ch ap = if prize > 13 then Nothing else (Just prize)
             where (a,b) = (comuns ch ap)
                   prize = (1 + (5 - a) * 3 + (2 - b))

instance Eq Aposta where
    (==) = equal



isInt :: String -> Bool
isInt [] = False
isInt str = and (map (isDigit) str)


insert :: [Int] -> Int -> Int-> [Int]
insert list x ch | inBounds x ch && (not (elem x list)) = x : list
                 | otherwise                         = list
                 where inBounds x ch | ch == 5 =  x >= 1 && x <= 50
                                     | ch == 2 = x >= 1 && x <= 9

leLista :: [Int] -> Int -> IO [Int]
leLista list x | length list == x = return list
               | otherwise = do
                    potentialNumber <- getLine
                    if (isInt potentialNumber) then
                        leLista (insert list (read potentialNumber :: Int) x) x
                    else
                        leLista list x




leAposta :: IO Aposta 
leAposta = do
    putStrLn "Introduzir numeros"
    list  <- leLista [] 5
    putStrLn "Introduzir estrelas"
    [e1, e2] <- leLista [] 2
    return (Ap list (e1,e2))



printRes :: Maybe Int -> IO ()
printRes Nothing = putStrLn "Nao ganhou nada :("
printRes (Just x) = putStrLn ("Ganhou o " ++ (show x) ++ " premio!!!")

joga :: Aposta -> IO ()
joga chave = do
    aposta <- leAposta
    let venceu = premio chave aposta
    printRes venceu


getRandom :: Int -> Int -> Int
getRandom mn mx = unsafePerformIO $ randomRIO (mn,mx)


geraLista :: Int -> Int -> [Int] -> [Int]
geraLista mx x list | length list == x = list
                    | otherwise        = geraLista mx x (insert list (getRandom 1 mx) 100)

geraChave :: Aposta
geraChave = (Ap nos (e1,e2))
          where nos = (geraLista 50 5 [])
                [e1, e2] = (geraLista 9 2 [])



ciclo :: Aposta -> IO ()
ciclo ch = do
    menu
    option <- getLine
    if(option == "1") then
        joga ch
    else if (option == "2") then
        ciclo (geraChave)
    else
        return ()


main :: IO ()
main = do
     let ch = geraChave 
     ciclo ch
     
     
     
menu :: IO String
menu = do { putStrLn menutxt
    ; putStr "Opcao: "
    ; c <- getLine
    ; return c}
    where menutxt = unlines ["","Apostar ........... 1","Gerar nova chave .. 2","","Sair .............. 0"]
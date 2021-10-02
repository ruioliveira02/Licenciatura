module Ficha1 where

import Data.Char

-- 1a -----------------------------------------------
-----------------------------------------------------
perimetroA :: Double -> Double
perimetroA radius = 2 * radius * pi

-- 1b -----------------------------------------------
-----------------------------------------------------
dist :: (Double, Double) -> (Double, Double) -> Double
dist (x1, y1) (x2, y2) = sqrt((x1-x2) ^ 2 + (y1-y2) ^ 2)

-- 1c------------------------------------------------
-----------------------------------------------------
primUlt :: [a] -> (a,a)
primUlt l = (head l, last l)

-- 1d -----------------------------------------------
-----------------------------------------------------
multiplo :: Integer -> Integer -> Bool
multiplo m n = ((mod m n) == 0)

-- 1e -----------------------------------------------
-----------------------------------------------------
truncaImpar :: [a] -> [a]
--truncaImpar l = if((mod (length l) 2) == 0) then l
                --else tail l

truncaImpar l | (mod (length l) 2 == 0)  = l
              | otherwise                =   tail l

-- 1f -----------------------------------------------
-----------------------------------------------------
max2 a b = if a > b then a else b

max3 a b c = max2 (max2 a b) c






-- 2 ------------------------------------------------
-----------------------------------------------------

nRaizes :: Double -> Double -> Double -> Int
nRaizes a b c | (b ^ 2 - 4 * a * c) > 0 = 2
              | (b ^ 2 - 4 * a * c) == 0 = 1
              | otherwise = 0

raizes :: Double -> Double -> Double -> [Double]
raizes a b c | nRaizes a b c == 2 = [(-b + sqrt (b ^ 2 - 4*a*c)) / (2*a), (-b - sqrt (b ^ 2 - 4*a*c)) / (2*a)]
             | nRaizes a b c == 1 = [(-b / (2*a))]
             | otherwise = []













-- 3 -----------------------------------------------
-----------------------------------------------------

type Hora = (Int, Int)

horaValida :: Hora -> Bool
horaValida (h,m) = h >= 0 && h < 24 && m >= 0 && m < 60

comparaHora :: Hora -> Hora -> Bool
--comparaHora (h1, m1) (h2, m2) = (h1 > h2) || (h1 == h2 && m1 > m2)
comparaHora (h1, m1) (h2, m2) |  h1 > h2 = True
                              |  h1 < h2 = False
                              |  m1 > m2 = True
                              | otherwise = False


horaParaMinutos :: Hora -> Int
horaParaMinutos (h, m) = h * 60 + m


minutosParaHora :: Int -> Hora
minutosParaHora m = (div m 60, mod m 60)

diferencaDeHoras :: Hora -> Hora -> Int
diferencaDeHoras a b = horaParaMinutos a - horaParaMinutos b

adicionarHora :: Hora -> Int -> Hora
adicionarHora a b = minutosParaHora ((horaParaMinutos a) + b)







-- 4 -----------------------------------------------
-----------------------------------------------------

data Hour = H Int Int deriving (Show, Eq)

horaValidaB :: Hour -> Bool
horaValidaB (H h m) = h >= 0 && h < 24 && m >= 0 && m < 60

comparaHoraB :: Hour -> Hour -> Bool
--comparaHora (h1, m1) (h2, m2) = (h1 > h2) || (h1 == h2 && m1 > m2)
comparaHoraB (H h1 m1) (H h2  m2)  |  h1 > h2 = True
                                   |  h1 < h2 = False
                                   |  m1 > m2 = True
                                   | otherwise = False


horaParaMinutosB :: Hour -> Int
horaParaMinutosB (H h m) = h * 60 + m


minutosParaHoraB :: Int -> Hour
minutosParaHoraB m = H (mod (div m 60) 24) (mod m 60)

diferencaDeHorasB :: Hour -> Hour -> Int
diferencaDeHorasB a b = abs (horaParaMinutosB a - horaParaMinutosB b)

adicionarHoraB :: Hour -> Int -> Hour
adicionarHoraB a b = minutosParaHoraB ((horaParaMinutosB a) + b)










-- 5 -----------------------------------------------
-----------------------------------------------------

data Semaforo = Verde
              | Amarelo
              | Vermelho
              deriving (Show, Eq)

next ::Semaforo -> Semaforo
next Verde    = Amarelo
next Amarelo  = Vermelho
next Vermelho = Verde


stop :: Semaforo -> Bool
stop Verde = False
stop semaforo = True

safe :: Semaforo -> Semaforo -> Bool
safe a b = (a == Vermelho || b == Vermelho)





-- 6 -----------------------------------------------
-----------------------------------------------------

data Ponto = Cartesiano Double Double | Polar Double Double deriving (Show,Eq)

posx :: Ponto -> Double
posx (Cartesiano a b) = a
posx (Polar p o) = p * (cos o)

posy :: Ponto -> Double
posy (Cartesiano a b) = b
posy (Polar p o) = p * (sin o)

posxA :: Ponto -> Double
posxA a = abs (posx a);

posyA :: Ponto -> Double
posyA a = abs (posy a);

raio :: Ponto -> Double
raio (Cartesiano a b) = sqrt (a ^ 2 + b ^ 2)
raio (Polar p o) = p

angulo :: Ponto -> Double
angulo (Cartesiano a b) = atan (b / a)
angulo (Polar p o) = o

distB :: Ponto -> Ponto -> Double
distB a b = sqrt (((posx a) - (posx b)) ^ 2 + ((posy a) - (posy b)) ^2)







-- 7 -----------------------------------------------
-----------------------------------------------------
data Figura = Circulo Ponto Double | Retangulo Ponto Ponto | Triangulo Ponto Ponto Ponto deriving (Show, Eq)

poligono :: Figura -> Bool
poligono (Circulo p d) = False
poligono f = True

vertices :: Figura -> [Ponto]
vertices (Circulo p d) = []
vertices (Retangulo a b) = [a, b, (Cartesiano (posx a) (posy b)), (Cartesiano (posx b) (posy a))]
vertices (Triangulo a b c) = [a, b, c]

area :: Figura -> Double
area (Triangulo p1 p2 p3) = 
    let a = distB p1 p2
        b = distB p2 p3
        c = distB p3 p1
        s = (a+b+c) / 2
    in sqrt (s*(s-a)*(s-b)*(s-c)) -- formula de Heron

area (Circulo p r) = pi * r ^ 2
area (Retangulo a b) = (abs ((posx a) - (posx b)))

perimetro :: Figura -> Double
perimetro (Triangulo a b c) = (distB a b) + (distB a c) + (distB b c)
perimetro (Retangulo a b) = 2 * (abs ((posx a) - (posx b))) + 2 * (abs ((posy a) - (posy b)))
perimetro (Circulo c r) = pi * 2 * r





-- 8 -----------------------------------------------
-----------------------------------------------------

isLowerA :: Char -> Bool
isLowerA a = (ord a) >= (ord 'a') && (ord a) < (ord 'A')

isDigitA :: Char -> Bool
isDigitA a = (ord a) >= (ord '0') && (ord a) <= (ord '9')

isAlphaA :: Char -> Bool
isAlphaA a = (ord a) >= (ord 'A') && (ord a) <= (ord 'z')

toUpperA :: Char -> Char
toUpperA a = chr ((ord a) - 26)

intToDigitA :: Int -> Char
intToDigitA a = chr ((ord '0') + a)

digitToIntA :: Char -> Int
digitToIntA a = ((ord a) - (ord '0'))

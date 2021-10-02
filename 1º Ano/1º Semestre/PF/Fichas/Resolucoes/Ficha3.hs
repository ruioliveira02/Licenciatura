module Ficha3 where

import Ficha1

type Etapa = (Hora,Hora)
type Viagem = [Etapa]

testarEtapa :: Etapa -> Bool
testarEtapa (a,b) = horaValida a && horaValida b && diferencaDeHoras b a > 0


testarViagem :: Viagem -> Bool
testarViagem [a] = testarEtapa a
testarViagem ((x,y):(x1,y1):t) 
      | testarEtapa (x, y) && diferencaDeHoras x1 y > 0 = testarViagem ((x1,y1):t)
      | otherwise                                       = False



partidaEChegada :: Viagem -> (Hora, Hora)
partidaEChegada [(a,b)] = (a,b)
partidaEChegada ((a,b):xs) = (a, snd (partidaEChegada xs))


tempoEfetivo :: Viagem -> Int
tempoEfetivo [] = 0
tempoEfetivo (e:es) = diferencaDeHoras (snd e) (fst e) + tempoEfetivo es


tempoEspera :: Viagem -> Int
tempoEspera [x] = 0
tempoEspera ((a,b):(c,d):t) = diferencaDeHoras c b + tempoEspera ((c,d):t)


tempoViagem :: Viagem -> Int
tempoViagem a = tempoEfetivo a + tempoEspera a















type Poligonal = [Ponto]

comprimentoLinha :: Poligonal -> Double
comprimentoLinha [x] = 0
comprimentoLinha (x:y:t) = distB x y + comprimentoLinha (y:t)


fechada :: Poligonal -> Bool
fechada (x:y:t) = distB x  (last (y:t)) == 0


pontoMedio :: Ponto -> Ponto -> Ponto
pontoMedio a b = Cartesiano ((posx b - posx a) / 2.0) ((posy b - posy a) / 2.0)



triangulaAux :: Poligonal -> Ponto -> [Figura]
triangulaAux [x,y] p = [Triangulo x y p]
triangulaAux (x:y:xs) p = Triangulo x y p : triangulaAux (y:xs) p


triangula :: Poligonal -> [Figura]
triangula (x:y:z:t) = triangulaAux (x:y:z:t) (pontoMedio x z)

calculaAreaAux :: [Figura] -> Double
calculaAreaAux [] = 0.0
calculaAreaAux (x:xs) = area x + calculaAreaAux xs

calculaArea :: Poligonal -> Double
calculaArea (x:y:z:t) = calculaAreaAux (triangula (x:y:z:t))



moverAux :: Ponto -> Poligonal -> Poligonal -> Poligonal
moverAux _ [] _ = []
moverAux pt (p:ps) cur | (distB pt p) == 0 = [pt] ++ ps ++ cur ++ [pt]
                       | otherwise         = moverAux pt ps (cur ++ [pt])

mover :: Ponto -> Poligonal -> Poligonal
mover a pt = moverAux a (drop 1 pt) []

somar :: Ponto -> Ponto -> Ponto
somar p1 p2 = Cartesiano (posx p1 + posx p2) (posy p1 + posy p2)

fazerZoom :: Double -> Ponto -> Ponto -> Ponto
fazerZoom d p1 p2 = somar p1 v
                    where v = Cartesiano (2*((posx p2) - (posx p1))) (2*((posy p2) - (posy p1)))


zoomAux :: Double -> Ponto -> Poligonal -> Poligonal
zoomAux _ _ [x] = []
zoomAux d pt (x:y:xs) = n : zoomAux d n (y : xs)
                      where n = somar (Cartesiano (2*((posx y) - (posx x))) (2*((posy y) - (posy x)))) pt
zoom :: Double -> Poligonal -> Poligonal
zoom _ [x] = [x]
zoom d (x:y:xs) = x : zoomAux d x (x:y:xs)














data Contacto = Casa Integer
                | Trab Integer
                | Tlm Integer
                | Email String
                deriving Show

type Nome   = String
type Agenda = [(Nome, [Contacto])]


acrescEmail :: Nome -> String -> Agenda -> Agenda
acrescEmail nm str [] = [(nm, [Email str])]
acrescEmail nm str (a:as)
                        | nm == (fst a) = (nm, snd a ++ [Email str]) : as
                        | otherwise = a : acrescEmail nm str as



getEmails ::[Contacto] -> [String]
getEmails [] = []
getEmails ((Email s):t) = s : getEmails t
getEmails (x:xs) = getEmails xs

verEmails :: Nome -> Agenda -> Maybe [String]
verEmails _ [] = Nothing
verEmails x (a:as)
                | (fst a) == x = Just (getEmails (snd a))
                | otherwise    = verEmails x as



consTelefs :: [Contacto] -> [Integer]
consTelefs [] = []
consTelefs ((Casa e):t) = e : consTelefs t
consTelefs ((Trab e):t) = e : consTelefs t
consTelefs ((Tlm e):t) = e : consTelefs t
consTelefs (x:xs) = consTelefs xs


getCasa :: [Contacto] -> Maybe Integer
getCasa [] = Nothing
getCasa ((Casa a):t) = Just a
getCasa (x:xs) = getCasa xs

casa :: Nome -> Agenda -> Maybe Integer
casa _ []  = Nothing
casa nm (a:as) | nm == (fst a) = getCasa (snd a)
               | otherwise     = casa nm as











type Dia = Int
type Mes = Int
type Ano = Int
data Data = D Dia Mes Ano deriving Show
type TabDN = [(Nome,Data)]


procura :: Nome -> TabDN -> Maybe Data
procura _ [] = Nothing
procura a ((n, d):xs) | a == n    = Just d
                      | otherwise = procura a xs



anos :: Data -> Data -> Int
anos (D d1 m1 a1) (D d2 m2 a2) = a1 - a2 - x
                                where x = if (m1 > m2 || (m1 == m2 && d1 >= d2)) then 0 else 1

idade :: Data -> Nome -> TabDN -> Maybe Int
idade dt nome tabdn = case x of 
                      Nothing  -> Nothing
                      Just a   -> Just (anos dt a)
                    where x = procura nome tabdn



anterior :: Data -> Data -> Bool
anterior (D d1 m1 a1) (D d2 m2 a2)
                                | a1 < a2   = True
                                | a1 > a2   = False
                                | m1 < m2   = True
                                | m1 > m2   = False
                                | d1 < d2   = True
                                | otherwise = False



divide :: TabDN -> Data -> (TabDN, TabDN)
divide [] _ = ([], [])
divide ((n,d):xs) x | anterior d x = ((n,d) : a, b)
                    | otherwise = (a, (n,d) : b)
                    where (a,b) = divide xs x

ordena :: TabDN -> TabDN
ordena [] = []
ordena (x:xs) = ordena (fst a) ++ [x] ++ ordena (snd a)
            where a = divide xs (snd x)


obterIdade :: Data -> TabDN -> [(Nome, Int)]
obterIdade _ [] = []
obterIdade dt ((n,d):xs) = (n, anos dt d) : obterIdade dt xs

porIdade :: Data -> TabDN -> [(Nome, Int)]
porIdade dt tabdn = obterIdade dt (reverse (ordena tabdn))










data Movimento = Credito Float | Debito Float deriving Show
data Extracto = Ext Float [(Data, String, Movimento)] deriving Show


extValor :: Extracto -> Float -> [Movimento]
extValor (Ext _ []) _ = []
extValor (Ext as ((d,n,(Credito m)):xs)) f 
                                        | m > f     = (Credito m) : extValor (Ext as xs) f
                                        | otherwise = extValor (Ext as xs) f
extValor (Ext as ((d,n,(Debito m)):xs)) f 
                                        | m > f     = (Debito m) : extValor (Ext as xs) f
                                        | otherwise = extValor (Ext as xs) f
                                            


extValor' :: Extracto -> Float -> [Movimento]
extValor' (Ext _ list) f = filter (maior f) (map (\(a,b,c)-> c) list)
                         where maior :: Float -> Movimento -> Bool
                               maior f (Credito fl) = f > fl
                               maior f (Debito fl)  = f > fl




contains :: Eq a => [a] -> a -> Bool
contains [] _ = False
contains (x:xs) a | a == x = True
                  | otherwise = contains xs a

filtro :: Extracto -> [String] -> [(Data, Movimento)]
filtro (Ext fl []) _ = []
filtro (Ext fl ((d,s, m):xs)) a | contains a s = (d,m) : resto
                              | otherwise      = resto
                              where resto = filtro (Ext fl xs) a


creDeb :: Extracto -> (Float, Float)
creDeb (Ext as [])                       = (0,0)
creDeb (Ext as ((d, s, (Credito c)):xs)) = (c + a, b) where (a,b) = creDeb (Ext as xs)
creDeb (Ext as ((d, s, (Debito c)):xs))  = (a, b + c) where (a,b) = creDeb (Ext as xs)



saldo :: Extracto -> Float
saldo (Ext s [])                   = s
saldo (Ext s ((d,m,Credito c):xs)) = saldo (Ext (s-c) xs)
saldo (Ext s ((d,m,Debito c):xs))  = saldo (Ext (s-c) xs)

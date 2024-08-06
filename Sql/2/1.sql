-- Drop DataBase A;
Create Database A;
Use A;

CREATE TABLE tb_estudio ( IDEstudio INT NOT NULL PRIMARY KEY, Nome
VARCHAR(45) NOT NULL,
Proprietario VARCHAR(45) NOT NULL,
FaturamentoAnoAnterior DECIMAL(12,2) NOT NULL,
DataFundacao DATE NOT NULL
) DEFAULT CHARSET=utf8;
CREATE TABLE tb_filmes ( IDFilme INT NOT NULL PRIMARY KEY,
Meses INT NOT NULL,
Nome VARCHAR(45) NOT NULL, AnoLancamento YEAR NOT NULL,
CustoTotal DECIMAL(12,2) NOT NULL,
IDEstudio INT NOT NULL, FOREIGN KEY (IDEstudio) REFERENCES tb_estudio
(IDEstudio)
) DEFAULT CHARSET=utf8;
CREATE TABLE tb_atores ( IDAtor INT NOT NULL PRIMARY KEY,
Nome VARCHAR(45) NOT NULL,
Nacionalidade VARCHAR(45) NOT NULL,
Idade INT NOT NULL, Sexo CHAR(1) NOT NULL
) DEFAULT CHARSET=utf8;
CREATE TABLE tb_papel (
IDPapel INT NOT NULL PRIMARY KEY,
CacheAtor DECIMAL(12,2) NOT NULL,
Personagem VARCHAR(45) NOT NULL,
IDAtor INT NOT NULL, IDFilme INT NOT NULL, FOREIGN KEY (IDAtor)
REFERENCES tb_atores (IDAtor),
FOREIGN KEY (IDFilme) REFERENCES tb_filmes (IDFilme)
) DEFAULT CHARSET=utf8;
INSERT INTO tb_estudio (IDEstudio, Nome, Proprietario, FaturamentoAnoAnterior,
DataFundacao) VALUES
(1, "Warner Bros.", "John Stankey", 2500000, "1923-04-04"),
(2, "Universal Pictures", "Jeff Shell", 3000000, "1912-06-08"),

(3, "Paramount Pictures", "Brian Robbins", 2800000, "1912-05-08"),
(4, "20th Century Fox", "James Murdoch", 2200000, "1935-05-31"),
(5, "Sony Pictures", "Tony Vinciquerra", 2100000, "1987-10-07"),
(6, "Netflix", "Reed Hastings", 5000000, "1997-08-29"),
(7, "Disney", "Bob Chapek", 4900000, "1923-10-16"),
(8, "Lionsgate", "Jon Feltheimer", 1300000, "1997-07-10");
INSERT INTO tb_filmes (IDFilme, Meses, Nome, AnoLancamento, CustoTotal,
IDEstudio) VALUES
(1, 18, "The Batman", 2022, 1850000, 1),
(2, 12, "Jurassic World: Dominion", 2022, 160000000, 2),
(3, 15, "Mission: Impossible - Fallout", 2018, 178000000, 3),
(4, 20, "Avatar", 2009, 237000000, 4),
(5, 10, "Spider-Man: No Way Home", 2021, 205000000, 5),
(6, 24, "Red Notice", 2021, 220000000, 6),
(7, 16, "Frozen II", 2019, 150000000, 7),
(8, 14, "John Wick: Chapter 3 – Parabellum", 2019, 75000000, 8),
(9, 11, "Tenet", 2020, 210000000, 1),
(10, 12, "Fast &amp; Furious 9", 2021, 250000000, 2),
(11, 18, "Top Gun: Maverick", 2022, 170000000, 3),
(12, 13, "Deadpool", 2016, 58000000, 4), (13, 16, "Jumanji: The Next Level", 2019,
132000000, 5),
(14, 12, "The Irishman", 2019, 159000000, 6), (15, 17, "Black Panther", 2018,
200000000, 7),
(16, 9, "Knives Out", 2019, 40000000, 8);
INSERT INTO tb_atores (IDAtor, Nome, Nacionalidade, Idade, Sexo) VALUES
(1, "Robert Pattinson", "Britânica", 36, "M"),
(2, "Chris Pratt", "Americana", 44, "M"),
(3, "Tom Cruise", "Americana", 61, "M"),
(4, "Sam Worthington", "Australiana", 47, "M"),
(5, "Tom Holland", "Britânica", 27, "M"),
(6, "Dwayne Johnson", "Americana", 52, "M"),
(7, "Idina Menzel", "Americana", 53, "F"),
(8, "Keanu Reeves", "Canadense", 59, "M"),
(9, "John David Washington", "Americana", 39, "M"),
(10, "Vin Diesel", "Americana", 56, "M"),
(11, "Tom Cruise", "Americana", 61, "M"),
(12, "Ryan Reynolds", "Canadense", 47, "M"),
(13, "Dwayne Johnson", "Americana", 52, "M"),
(14, "Joe Pesci", "Americana", 81, "M"),
(15, "Chadwick Boseman", "Americana", 43, "M"),
(16, "Chris Evans", "Americana", 43, "M"),
(17, "Ana de Armas", "Cubana", 36, "F"), (18, "Chris Hemsworth", "Australiana", 40, "M");
INSERT INTO tb_papel (IDPapel, CacheAtor, Personagem, IDAtor, IDFilme) VALUES
(1, 120000, "Bruce Wayne / Batman", 1, 1),
(2, 160000, "Owen Grady", 2, 2),

(3, 250000, "Ethan Hunt", 3, 3),
(4, 60000, "Jake Sully", 4, 4),
(5, 45000, "Peter Parker / Spider-Man", 5, 5),
(6, 230000, "John Hartley", 6, 6),
(7, 7500, "Elsa", 7, 7),
(8, 140000, "John Wick", 8, 8),
(9, 110000, "The Protagonist", 9, 9),
(10, 130000, "Dominic Toretto", 10, 10),
(11, 220000, "Maverick", 11, 11),
(12, 140000, "Wade Wilson / Deadpool", 12, 12),
(13, 200000, "Spencer", 13, 13),
(14, 120000, "Frank Sheeran", 14, 14),
(15, 250000, "T\"Challa / Black Panther", 15, 15),
(16, 150000, "Ransom Drysdale", 16, 16);

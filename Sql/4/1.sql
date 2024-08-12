Drop DataBase A4;
Create Database if not exists A4;
Use A4;

Create Table if not exists Pai
(
	IDPai int Primary Key,
    Nome Varchar(50)
);

Create Table if not exists Filho
(
	IDFilho int Primary Key,
    Nome Varchar(50),
    IDPai int,
    foreign key (IDPai) references Pai(IDPai)
    on update cascade
    on delete cascade
);

insert into Pai Values
(1, "Darth Vader"),
(2, "Goku"),
(3, "Vegeta"),
(4, "Seu Cebola"),
(5, "Zurg"),
(6, "Neymar");

insert into Filho Values
(1, "Luke Skywalker", 1),
(2, "Gohan", 2),
(3, "Trunks", 3),
(4, "Cebolinha", 4),
(5, "Buzz Lightyear", 5),
(6, "Neymar Jr", 6);

delete from Filho where IDFilho = 4;
-- Não acontece nada com o Seu Cebola

delete from Pai where IDPai = 6;
-- Tanto o Neymar quanto o Neymar Jr são eliminados

Select * From Filho Right Join Pai on Pai.IDPai = Filho.IDPai;
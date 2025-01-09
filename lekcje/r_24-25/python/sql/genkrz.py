import random
import itertools


def gen():
    il_konkursow = 40

    konkursy = {
        "id_konkursu": [str(i) for i in range(il_konkursow)],
        "nazwa": [
            "Konkurs wiedzy o Janie Pawle II",
            "Konkurs wiedzy o Lechu Wałęsie",
            "Konkurs wiedzy o Kardynale Wyszyńskim",
            "Konkurs wiedzy o Józefie Piłsudskim",
            "Konkurs wiedzy o piłce nożnej",
            "Konkurs wiedzy o polityce",
            "Konkurs wiedzy o historii Polski",
            "Konkurs wiedzy o historii świata",
            "Konkurs wiedzy ekonomicznej",
            "Konkurs wiedzy o sporcie",
            "Konkurs wiedzy o skandynawii",
            "Konkurs wiedzy o Azji",
            "Konkurs wiedzy o Afryce",
            "Konkurs wiedzy o Ameryce",
            "Konkurs wiedzy o Chopinie",
            "Konkurs wiedzy o Unii Europejskiej",
            "Konkurs wiedzy o kosmosie",
            "Konkurs wiedzy o zdrowiu",
            "Konkurs wiedzy o ekologii",
            "Konkurs wiedzy o sztuce",
            "Konkurs wiedzy o literaturze",
            "Konkurs wiedzy o filmie",
            "Konkurs wiedzy o muzyce",
            "Konkurs wiedzy o teatrze",
            "Konkurs wiedzy o fotografii",
            "Konkurs wiedzy o informatyce",
            "Konkurs wiedzy o matematyce",
            "Konkurs wiedzy o fizyce",
            "Konkurs wiedzy o chemii",
            "Konkurs wiedzy o biologii",
            "Konkurs wiedzy o historii",
            "Konkurs wiedzy o geografii",
            "Konkurs wiedzy o literaturze polskiej",
            "Konkurs wiedzy o literaturze światowej",
            "Konkurs wiedzy o sztuce współczesnej",
            "Konkurs wiedzy o sztuce renesansu",
            "Konkurs wiedzy o sztuce baroku",
            "Konkurs wiedzy o sztuce romantyzmu",
            "Konkurs wiedzy o sztuce modernizmu",
            "Konkurs znajomości twórczości Bartosza Walaszka",
        ],
        "przedzial_wiekowy": ["5-10"]
        + [
            random.choice(
                ["5-10", "11-15", "16-25", "26-35", "36-50", "51-65", "66-100"]
            )
            for _ in range(il_konkursow - 2)
        ]
        + ["0-100"],
        "kiedy": [
            f"{random.randint(1990, 2030)}-{random.randint(1, 12):02d}-{random.randint(1, 28):02d}"
            for _ in range(il_konkursow)
        ],
        "czas_trwania": [str(random.randint(2, 42) * 10) for _ in range(il_konkursow)],
    }

    il_uczestnikow = 3000

    imiona_meskie = [
        "Adam",
        "Adrian",
        "Albert",
        "Aleksander",
        "Andrzej",
        "Antoni",
        "Arkadiusz",
        "Artur",
        "Bartłomiej",
        "Bartosz",
        "Błażej",
        "Bogdan",
        "Borys",
        "Brunon",
        "Cezary",
        "Cyprian",
        "Damian",
        "Daniel",
        "Dariusz",
        "Dawid",
        "Dominik",
        "Edward",
        "Emil",
        "Eryk",
        "Filip",
        "Franciszek",
        "Fryderyk",
        "Gabriel",
        "Grzegorz",
        "Henryk",
        "Hubert",
        "Ignacy",
        "Igor",
        "Ireneusz",
        "Jacek",
        "Jakub",
        "Jan",
        "Janusz",
        "Jarosław",
        "Jerzy",
        "Józef",
        "Julian",
        "Kacper",
        "Kajetan",
        "Karol",
        "Kazimierz",
        "Krzysztof",
        "Leon",
        "Leszek",
        "Łukasz",
        "Zbigniew",
        "Władysław",
        "Zygmunt",
        "Teofil",
        "Szczepan",
        "Radosław",
        "Przemysław",
        "Mieszko",
        "Lech",
        "Bogusław",
    ]

    nazwiska_meskie = [
        "Kowalski",
        "Nowak",
        "Wiśniewski",
        "Wójcik",
        "Kowalczyk",
        "Kamiński",
        "Lewandowski",
        "Zieliński",
        "Szymański",
        "Woźniak",
        "Dąbrowski",
        "Kozłowski",
        "Jankowski",
        "Mazur",
        "Wojciechowski",
        "Kwiatkowski",
        "Krawczyk",
        "Kaczmarek",
        "Piotrowski",
        "Grabowski",
        "Zając",
        "Pawłowski",
        "Michalski",
        "Król",
        "Wieczorek",
        "Jabłoński",
        "Wróbel",
        "Nowakowski",
        "Majewski",
        "Olszewski",
        "Stępień",
        "Malinowski",
        "Jaworski",
        "Adamczyk",
        "Dudek",
        "Nowicki",
        "Pawlak",
        "Górski",
        "Witkowski",
        "Walczak",
        "Sikora",
        "Baran",
        "Rutkowski",
        "Michalak",
        "Szewczyk",
        "Ostrowski",
        "Tomaszewski",
        "Pietrzak",
        "Zalewski",
        "Wróblewski",
    ]

    imiona_zenskie = [
        "Agnieszka",
        "Aleksandra",
        "Alicja",
        "Amelia",
        "Anna",
        "Barbara",
        "Beata",
        "Bogumiła",
        "Bożena",
        "Cecylia",
        "Celina",
        "Dagmara",
        "Danuta",
        "Dorota",
        "Edyta",
        "Elżbieta",
        "Emilia",
        "Ewa",
        "Gabriela",
        "Grażyna",
        "Halina",
        "Hanna",
        "Helena",
        "Irena",
        "Izabela",
        "Jadwiga",
        "Janina",
        "Joanna",
        "Jolanta",
        "Julia",
        "Justyna",
        "Kamila",
        "Karolina",
        "Katarzyna",
        "Kazimiera",
        "Kinga",
        "Krystyna",
        "Laura",
        "Lidia",
        "Liliana",
        "Lucyna",
        "Magdalena",
        "Małgorzata",
        "Maria",
        "Marta",
        "Monika",
        "Natalia",
        "Nina",
        "Olga",
        "Patrycja",
        "Bronisława",
        "Genowefa",
        "Kunegunda",
        "Leokadia",
        "Pelagia",
        "Rozalia",
        "Teodora",
        "Wanda",
        "Zofia",
        "Żaneta",
    ]

    nazwiska_zenskie = [
        "Kowalska",
        "Nowak",
        "Wiśniewska",
        "Wójcik",
        "Kowalczyk",
        "Kamińska",
        "Lewandowska",
        "Zielińska",
        "Szymańska",
        "Woźniak",
        "Dąbrowska",
        "Kozłowska",
        "Jankowska",
        "Mazur",
        "Wojciechowska",
        "Kwiatkowska",
        "Krawczyk",
        "Kaczmarek",
        "Piotrowska",
        "Grabowska",
        "Zając",
        "Pawłowska",
        "Michalska",
        "Król",
        "Wieczorek",
        "Jabłońska",
        "Wróbel",
        "Nowakowska",
        "Majewska",
        "Olszewska",
        "Stępień",
        "Malinowska",
        "Jaworska",
        "Adamczyk",
        "Dudek",
        "Nowicka",
        "Pawlak",
        "Górska",
        "Witkowska",
        "Walczak",
        "Sikora",
        "Baran",
        "Rutkowska",
        "Michalak",
        "Szewczyk",
        "Ostrowska",
        "Tomaszewska",
        "Pietrzak",
        "Zalewska",
        "Wróblewska",
    ]

    uczestnicy = {
        "id_uczestnika": [str(i) for i in range(1, il_uczestnikow + 1)],
        "id_konkursu": [
            random.choice(konkursy["id_konkursu"]) for _ in range(il_uczestnikow)
        ],
        "imie": [
            " ".join(x)
            for x in random.sample(
                list(itertools.product(imiona_meskie, nazwiska_meskie)),
                il_uczestnikow // 2,
            )
            + random.sample(
                list(itertools.product(imiona_zenskie, nazwiska_zenskie)),
                il_uczestnikow // 2,
            )
        ],
        "wiek": [str(random.randint(5, 100)) for _ in range(il_uczestnikow)],
    }

    nagrody = {
        "id_konkursu": [str(i) for i in range(il_konkursow)],
        "nagroda 1": [
            random.choice(
                [
                    "Laptop",
                    "Tablet",
                    "Smartfon",
                    "Smartwatch",
                    "Czytnik E-booków",
                    "Jan Paweł II. Autobiografia",
                    "Koszulka z autografem Walaszka",
                    "Zapas kremówek do końca życia",
                ]
            )
            for _ in range(il_konkursow)
        ],
        "nagroda 2": [
            random.choice(
                [
                    "Voucher",
                    "Słuchawki",
                    "Głośnik Bluetooth",
                    "Power Bank",
                    "Pendrive",
                    "Kubek z kremówkami",
                ]
            )
            for _ in range(il_konkursow)
        ],
        "nagroda 3": [
            random.choice(
                [
                    "Książka",
                    "Gra planszowa",
                    "Puzzle",
                    "Karta podarunkowa",
                    "Zestaw długopisów",
                    "Uścisk dłoni prezesa",
                ]
            )
            for _ in range(il_konkursow)
        ],
        "nagroda wyroznienia": [
            random.choice(
                [
                    "Medal",
                    "Certyfikat",
                    "Trofeum",
                    "Odznaka",
                    "Wstążka",
                    "Talon na balon",
                    "Medal z ziemniaka",
                ]
            )
            for _ in range(il_konkursow)
        ],
    }

    return konkursy, uczestnicy, nagrody


def main():
    konkursy, uczestnicy, nagrody = gen()
    print(konkursy)
    print(uczestnicy)
    print(nagrody)

    with open("konkursy.txt", "w") as f:
        f.writelines("\n".join("\t".join(x) for x in list(zip(*konkursy.values()))))

    with open("uczestnicy.txt", "w") as f:
        f.writelines("\n".join("\t".join(x) for x in list(zip(*uczestnicy.values()))))

    with open("nagrody.txt", "w") as f:
        f.writelines("\n".join("\t".join(x) for x in list(zip(*nagrody.values()))))


if __name__ == "__main__":
    main()

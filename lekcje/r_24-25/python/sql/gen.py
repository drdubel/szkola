import random
import itertools


def gen():
    il_jachtow = 15

    jachty = {
        "jacht_id": [str(i) for i in range(il_jachtow)],
        "model": [
            "Antilla 22",
            "Antilla 24",
            "Antilla 28",
            "Antilla 30",
            "Antilla 32",
            "Bavaria 34",
            "Jeanneau 36",
            "Beneteau 38",
            "Hanse 40",
            "Dufour 42",
            "Elan 44",
            "Delphia 46",
            "Sun Odyssey 48",
            "Oceanis 50",
            "Lagoon 52",
        ],
        "dlugosc": [
            "6.7",
            "7.3",
            "8.5",
            "9.1",
            "9.7",
            "10.3",
            "11.5",
            "12.1",
            "12.7",
            "13.3",
            "14.5",
            "15.1",
            "15.7",
            "16.3",
            "17.5",
        ],
        "szerokość": [
            "2.5",
            "2.7",
            "2.9",
            "3.1",
            "3.3",
            "3.5",
            "3.7",
            "3.9",
            "4.1",
            "4.3",
            "4.5",
            "4.7",
            "4.9",
            "5.1",
            "5.3",
        ],
        "zanurzenie": [
            "1.3",
            "1.5",
            "1.7",
            "1.9",
            "2.1",
            "2.3",
            "2.5",
            "2.7",
            "2.9",
            "3.1",
            "3.3",
            "3.5",
            "3.7",
            "3.9",
            "4.1",
        ],
        "ilosc_koi": [
            "4",
            "6",
            "8",
            "10",
            "12",
            "14",
            "16",
            "18",
            "20",
            "22",
            "24",
            "26",
            "28",
            "30",
            "32",
        ],
    }

    il_ofert = 1500

    oferty = {
        "jacht_id": [random.choice(jachty["jacht_id"]) for _ in range(il_ofert)],
        "oferta_id": [str(i) for i in range(il_ofert)],
        "cena": [str(random.randint(100, 1000) * 1000) for _ in range(il_ofert)],
        "data_produkcji": [
            f"{random.randint(1990, 2024)}-{random.randint(1, 12):02d}-{random.randint(1, 28):02d}"
            for _ in range(il_ofert)
        ],
        "port": [
            random.choice(
                [
                    "Gdańsk",
                    "Gdynia",
                    "Sopot",
                    "Kołobrzeg",
                    "Świnoujście",
                    "Ustka",
                    "Łeba",
                    "Hel",
                    "Władysławowo",
                    "Jastarnia",
                    "Darłowo",
                    "Dziwnów",
                    "Międzyzdroje",
                    "Rewal",
                ]
            )
            for _ in range(il_ofert)
        ],
    }

    il_klientow = 100

    imiona_meskie = [
        "Jan",
        "Piotr",
        "Marek",
        "Tomasz",
        "Paweł",
        "Krzysztof",
        "Andrzej",
        "Adam",
        "Łukasz",
        "Michał",
        "Rafał",
        "Grzegorz",
        "Marcin",
    ]
    imiona_zenskie = [
        "Anna",
        "Katarzyna",
        "Agnieszka",
        "Magdalena",
        "Joanna",
        "Ewa",
        "Monika",
        "Dorota",
        "Barbara",
        "Beata",
        "Aleksandra",
        "Małgorzata",
        "Elżbieta",
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
    ]

    klienci = {
        "oferta_id": random.sample(oferty["oferta_id"], il_klientow),
        "imie": [
            " ".join(x)
            for x in random.sample(
                list(itertools.product(imiona_meskie, nazwiska_meskie)), il_klientow / 2
            )
            + random.sample(
                list(itertools.product(imiona_zenskie, nazwiska_zenskie)),
                il_klientow / 2,
            )
        ],
        "email": [
            f"user{i}@gmail.com" for i in random.sample(range(1, 150001), il_klientow)
        ],
        "telefon": random.sample(
            [
                f"{random.randint(100000000, 999999999)}"
                for _ in range(il_klientow * 10)
            ],
            il_klientow,
        ),
    }

    return jachty, oferty, klienci


def main():
    jachty, oferty, klienci = gen()
    # print(jachty)
    # print(oferty)
    # print(klienci)

    with open("jachty.txt", "w") as f:
        f.writelines("\n".join("\t".join(x) for x in list(zip(*jachty.values()))))

    with open("oferty.txt", "w") as f:
        f.writelines("\n".join("\t".join(x) for x in list(zip(*oferty.values()))))

    with open("klienci.txt", "w") as f:
        f.writelines("\n".join("\t".join(x) for x in list(zip(*klienci.values()))))


if __name__ == "__main__":
    main()

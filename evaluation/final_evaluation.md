# Bodové hodnocení pro tříčlenné týmy

## Plán
Lze získat max. 9 bodů:
- 1 bod za stanovení termínů,
- 1 bod za rozdělení práce a přidělení úkolů
- 1 bod za podrobné rozdělení práce
- 1 bod za komunikační kanály
- 1 bod za rozumné komunikační kanály
- 1 bod za pravidla pro komunikaci
- 1 bod za systém pro správu verzí
- 1 bod za zamyšlení
- 1 bod za kompletnost plánu (je z něj jasné, co kdo bude dělat a čím se bude komunikovat)
- 1 (bonusový) bod za využití nějakého systému pro plánování a sledování projektu

## Výsledný produkt

- 6 b. za existující a snadno přístupný repozitář (při dodatečném zpřístupnění min. 1 bod)
- 6 b. za korektní odevzdání všech požadovaných souborů (program, dokumentace, repozitář, instalátor, ...)
- 9 b. za matematickou knihovnu (základ, faktoriál, umocnění, odmocnina, vlastní funkce, rozumné rozhraní, správnost implementace, ...)
- 9 b. za testy k matematické knihovně (2 za přítomnost, 7 za kompletnost - testy hraničních hodnot apod.)
- 18 b. za funkční program (3 za GUI, 3 za korektní chování, 4 za korektní ošetření chyb, 2 za ovládání klávesnicí, 6 za uživatelskou přívětivost)
- 6 b. za instalátor a odinstalátor (za přítomnost, funkčnost, závislosti, ikonku v menu/na ploše, čistou odinstalaci, ...)
- 6 b. za nápovědu (1 za přítomnost, 2 za smysluplnost, 3 za kompletnost)
- 12 b. za komentáře a generovanou dokumentaci (funkce, metody, parametry, @file, @brief, rozumný Doxyfile, jazyk dokumentace odpovídá jazyku komentářů, ...)
- 9 b. za uživatelskou příručku (ovládání, závislosti, instalace, odinstalace, přehlednost, vzhled, formální a jazyková úprava, ...)
- 9 b. za Makefile (1 all, 1 pack, 1 clean, 1 test, 1 doc, 1 run, 1 za bezproblémovou kompilaci, 2 za automatické proměnné)
- 6 b. za debugging (pokud je screenshot, ale jinak je kalkulačka plná bugů, byl debugging proveden špatně a je max. za 3 b.)
- 9 b. za mockup (Splňuje zadání? Je jasné, jak to bude vypadat? Je jasné, jak to bude fungovat? Bude to uživatelsky přívětivé?)
- 12 b. za profiling (2 za program, 2 za funkčnost programu, 8 za protokol s měřením)
- 1 bonusový bod za Profile-Guided Optimization

# Hodnocení týmu

## Plán
- stanovení termínů: 1
- rozdělení práce a přidělení úkolů: 2
- komunikační kanály: 1
- pravidla pro komunikaci: 1
- systém pro správu verzí: 1
- zamyšlení: 1
- kompletnost plánu: 1
- bonusový bod: 1
------------------------------------
plán celkem (po případném oříznutí): 9
pro Vás (člena týmu): 3

## Výsledný produkt:
- vytvořený a přístupný repozitář: 6
- korektní odevzdání: 6
- matematická knihovna: 9
- testy k matematické knihovně: 9
- funkční program: 18
- instalátor a odinstalátor: 6
- nápověda: 6
- komentáře a generovaná dokumentace: 11.25
- uživatelská příručka: 7
- Makefile: 7.4
- debugging: 6
- mockup: 9
- profiling: 9
-------------------------------------
produkt celkem: 109,65
pro Vás (člena týmu): 37

## Dodatečné body
- Vyhodnocení rozdílů mezi plánem a skutečností: 1 (pro Vás 1)
- Používání repozitáře: 2
- Bonusové body: -
- Zhodnocení projektu (xloginNN_problemy.txt): 2
- Obhajoby: 5
- PGO (bonus): -

Přidělení bonusových bodů bylo zdůvodněno na obhajobách, v poznámkách k hodnocení či individuálně.

-------------------------------------

Celkem máte: 50 bodů

### Poznámky
- Chybí akutní komunikační prostředek. Co když si vedoucí v den odevzdáním utopí počítač?
- Bonus za použití ClickUp.
- Makefile:
-- nebyly využity automatické proměnné https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html
-- make pack: Při opakovaném volání se archív nevytvoří znovu, ale aktualizuje se (mohli by tam tak zůstat soubory, které byly odstraněny).
-- make profile: Spustí program pro výpočet směrodatné odchylky, což není žádané. Na to mohl být vytvořen jiný cíl, např. “profile_run”.
-- make doc: Nefunguje verze z IS FIT, ale verze ze složky ze serveru ivs funguje.
- Profiling:
-- protokol
--- chybí popis metody profilování (název programu či knihovny pomocí které jste profilovali)
- Práce s Gitem
-- obsah repozitáře: ok
-- commity: logicky strukturované
-- hlášky commitů: hezky výstižné
-- použití branches: ano
-- použití pull requests: ano
-- celkově hezká práce s Gitem
- Makefile: neobsahuje automatické proměnné
- Uživatelská příručka: Chybí snímek obrazovky/popis UI
- Generovaná dokumentace: chybí @file s @brief a některé komentáře

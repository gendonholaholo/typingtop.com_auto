# typingtop.com_autoCheat :)

## Install Dependencies using pip (Python):
1. `keyboard`
2. `pyautogui`
3. `beautifulsoup4`

## How to Use in Python:
1. Open [typingtop.com](https://typingtop.com/).
2. Start the typing test.
3. Once you are in the typing area, open **Inspect** in Chrome.
4. Find `<span wordnr="1" class="">xxx</span>`, and copy all content within the `<div>` that contains this `<span>`.
5. Then paste it into `span_cleaner.py`
6. Run `span_cleaner.py`
7. Finally run `type_it.py`

## How to Use in C++:
1. Open [typingtop.com](https://typingtop.com/).
2. Start the typing test.
3. Open terminal/cmd/prompt (whatever you call it)
4. Run `g++ .\type_it_gos.cpp -o .\type_it_gos` (don't forget to fill in the data in the `html_content.txt`)
5. Run `type_it_gos.exe`

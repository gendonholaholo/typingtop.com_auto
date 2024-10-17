# typingtop.com_autoCheat :)

## Install Dependencies:
1. `keyboard`
2. `pyautogui`
3. `beautifulsoup4`

## How to Use:
1. Open [typingtop.com](https://typingtop.com/).
2. Start the typing test.
3. Once you are in the typing area, open **Inspect** in Chrome.
4. Find `<span wordnr="1" class="">xxx</span>`, and copy all content within the `<div>` that contains this `<span>`.
5. Then paste it into `span_cleaner.py`
6. Run `span_cleaner.py`
7. Finally run `type_it.py`

# Questions

## What is pneumonoultramicroscopicsilicovolcanoconiosis?

a disease of the lungs resulting from the inhalation of very fine silicate or quartz dust'

## According to its man page, what does `getrusage` do?

get resource usage

## Per that same man page, how many members are in a variable of type `struct rusage`?

16

## Why do you think we pass `before` and `after` by reference (instead of by value) to `calculate`, even though we're not changing their contents?

to conserve memory

## Explain as precisely as possible, in a paragraph or more, how `main` goes about reading words from a file. In other words, convince us that you indeed understand how that function's `for` loop works.

Reads the first character of a file and ensures it is an alphabetical character. This is done by skipping over characters that
are not part of a word using a while loop and then setting index to 0. If a word is found, each letter is appended to a char array
entitled word and then terminated with a sentinel value before having its index set to 0 with a word counter being incremented
appropriately.  If the word is misspelled, it is printed along with its counter being incrememented while also being timed and
added to a total running time to benchmark.

## Why do you think we used `fgetc` to read each word's characters one at a time rather than use `fscanf` with a format string like `"%s"` to read whole words at a time? Put another way, what problems might arise by relying on `fscanf` alone?

because reading whole words at a time could be problemsome since some words might have punctuation

## Why do you think we declared the parameters for `check` and `load` as `const` (which means "constant")?

We dont want to change them

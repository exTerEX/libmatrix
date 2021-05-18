# Contributing

## Getting started

### Don't see your issue?

If you spot something new, open an issue using a template. We'll use the issue to have a conversation about the problem you want to fix.

### Ready to make a change?

1. Fork the project. If you don't know how to do this see [Fork the repo](https://docs.github.com/en/github/getting-started-with-github/fork-a-repo#fork-an-example-repository).
2. Change the files necessary, including documentation if needed.
3. Open a pull request & get it reviewed.

Always comply with the [CODE_OF_CONDUCT](https://github.com/exTerEX/libmatrix/blob/main/.github/CODE_OF_CONDUCT.md).

## Style and language

This project follow the LLVM style guide. It is provided a .clang-format file to control how some formatters will format the code, but this doesn't cover every aspect of the prefeered syntax. Most importantly on your part, not covered by formatters are **type names**. Use descriptive type names and try to mimic the STL interface when appropriate.

Futher details can be found at [llvm.org](https://llvm.org/docs/CodingStandards.html).

## Filestructure

When developing this

|  Folder / file | Description                                                      |
| -------------: | :--------------------------------------------------------------- |
|        .github | Contain files related to github docs, actions and configuration. |
|           data | Contain test files and/or data used for testing.                 |
|            doc | Contain code and documentation related to library.               |
|        example | Contain example of how to use the library.                       |
| include/matrix | Public header files for library.                                 |
|            src | Source code for library.                                         |
|           test | Code related to running unit and integration tests.              |

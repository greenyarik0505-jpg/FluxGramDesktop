# Contributing

This document describes how you can contribute to FluxGram Desktop.

**Table of Contents**

* [What contributions are accepted](#what-contributions-are-accepted)
* [Build instructions](#build-instructions)
* [Pull upstream changes into your fork regularly](#pull-upstream-changes-into-your-fork-regularly)
* [How to get your pull request accepted](#how-to-get-your-pull-request-accepted)
  * [Keep your pull requests limited to a single issue](#keep-your-pull-requests-limited-to-a-single-issue)
    * [Squash your commits to a single commit](#squash-your-commits-to-a-single-commit)
  * [Don't mix code changes with whitespace cleanup](#dont-mix-code-changes-with-whitespace-cleanup)
  * [Keep your code simple!](#keep-your-code-simple)
  * [Test your changes!](#test-your-changes)
  * [Write a good commit message](#write-a-good-commit-message)

## What contributions are accepted

We highly appreciate your contributions in the matter of fixing bugs and optimizing the FluxGram Desktop source code and its documentation. In case of fixing the existing user experience please push to your fork and [submit a pull request][pr].

## Build instructions

See [folder with instructions][build_instructions] for details on the various build environments.

## Pull upstream changes into your fork regularly

Telegram Desktop is advancing quickly. It is therefore critical that you pull upstream changes into your fork on a regular basis.

To pull in upstream changes:

    git remote add upstream https://github.com/greenyarik0505-jpg/FluxGramDesktop.git
    git fetch upstream dev

Then rebase your changes on the latest commits in the `dev` branch:

    git rebase upstream/dev

After that, you have to force push your commits:

    git push --force

## How to get your pull request accepted

We want to improve FluxGram Desktop with your contributions. Follow these rules and you should succeed without a problem!

### Keep your pull requests limited to a single issue

Pull requests should be as small/atomic as possible.

[//]: # (LINKS)
[pr]: https://github.com/greenyarik0505-jpg/FluxGramDesktop/compare
[build_instructions]: https://github.com/greenyarik0505-jpg/FluxGramDesktop/blob/dev/docs

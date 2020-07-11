#! /Python37/Python

import cgi

from headTail import headHtml

from headTail import tailHtml

from formIo import dispForm


def main():
    headHtml()
    dispForm()

    tailHtml()
    return


if __name__ == "__main__":

    try:

        main()

    except:

        cgi.print_exception()


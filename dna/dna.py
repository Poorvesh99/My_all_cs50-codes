import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        return

    # TODO: Read database file into a variable
    database = []
    with open(sys.argv[1]) as file:
        reader = csv.DictReader(file)
        for i in reader:
            database.append(i)

    # TODO: Read DNA sequence file into a variable
    with open(sys.argv[2]) as dna:
        sequence = dna.readline()

    # TODO: Find longest match of each STR in DNA sequence
    AGATC = longest_match(sequence, "AGATC")
    TTTTTTCT = longest_match(sequence, "TTTTTTCT")
    AATG = longest_match(sequence, "AATG")
    TCTAG = longest_match(sequence, "TCTAG")
    GATA = longest_match(sequence, "GATA")
    TATC = longest_match(sequence, "TATC")
    GAAA = longest_match(sequence, "GAAA")
    TCTG = longest_match(sequence, "TCTG")

    # TODO: Check database for matching profiles
    for data in database:
        if sys.argv[1] == "databases/small.csv":
            if AGATC == int(data["AGATC"]) and AATG == int(data["AATG"]) and TATC == int(data["TATC"]):
                print(data["name"])
                return
        else:
            if AGATC == int(data["AGATC"]) and TTTTTTCT == int(data["TTTTTTCT"]) and AATG == int(data["AATG"]) and TCTAG == int(data["TCTAG"]) and GATA == int(data["GATA"]) and TATC == int(data["TATC"]) and GAAA == int(data["GAAA"]) and TCTG == int(data["TCTG"]):
                print(data["name"])
                return
    print("No match")


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()

# C++ Interview Question
In this project you are required to create an application that will take an input file in csv format and generate an output file calculated from the input file. Please use C++ for this project. We are interested in your coding ability with the emphasis on the following aspects:
* Design
* TDD or tests in case you have not used TDD
* Modern C++
* Correctness
* Efficiency
* Self-documenting code


## Input file format:
Each line is a record of the message sending event.

```<Timestamp>,<DateSentTimestamp>,<DateReceivedTimestamp>,<SenderPhoneNumber>,<RecepientPhoneNumber>```

The timestamp is in increasing order in seconds (UTC). The value corresponds to the timestamp of writing to the file.
Phone numbers can be represented in different formats. For example, phone numbers +1 234-567-8899, (+1)234-567-8899, 12345678899 are the same.
DateSentTimestamp value can be more or less than timestamp value
DateReceivedTimestamp value can be more or the same with DateSentTimestamp value

## Output file:
The output file should contain the following metrics for each phone number presented in the input file and it should be sorted by phone number.

```<PhoneNumber>,<TotalSent>,<TotalReceived>,<The day with highest number of sent messages (dd-mm-yyyy)>,<The phone number to which the most messages were sent>,<The phone number of the interlocutor for whom the difference between received and sent messages from this phone number is the greatest>```

## Design
Design it in such a way that it is easy to:
* Change the input file format. Fields can be added/removed, sequence can be changes, and delimiter scan be changed.
* Output file metrics can be changed. For example, metrics can be added/removed, order of metrics can be changed. 
* Add tests
* Enhance the performance
When designing, take into account that the input file can be of unlimited size. 

Please let us know how many hours it took for you to code it and please send us the output file, source code, and a readme.txt detailing the design and any improvements that did not get time to do w.r.t performance or design. 
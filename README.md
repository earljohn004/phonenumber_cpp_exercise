# C++ Interview Question Solution

Refer to the INSTRUCTIONS.md for the full description of the problem.

## Requirements
* Change the input file format. Fields can be added/removed, sequence can be changes, and delimiter scan be changed.
* Output file metrics can be changed. For example, metrics can be added/removed, order of metrics can be changed. 

## Design
* The program has a config.xml file which contains sequence of the input fields and output fields. config.xml contains the delimeter setting which can also be changed.

```
<config>
	<delimeter_setting>,</delimeter_setting>
	<input_setting>
		<included>
			<TimeStamp/>
			<DateSentTimeStamp/>
			<DateReceivedTimeStamp/>
			<SenderPhoneNumber/>
			<RecepientPhoneNumber/>
		</included>
		<excluded>
		</excluded>
	</input_setting>

	<output_setting>
		<included>
			<PhoneNumber/>
			<TotalSent/>
			<TotalReceived/>
			<DayHighestSent/>
			<NumberHighestSent/>
		</included>
		<excluded>
			<DayHighestDifference/>
		</excluded>
	</output_setting>
</config>

```
* The main design utilizes the producer-consumer pattern. File is read from a file and pushed into a queue. When the queue buffer size is reached, file read thread is paused then the processing of data executes. When the queue size is now empty, the file read thread will resume. The program terminates when the end of file is reached.
* Output.txt is written when the end of file is reached.


## Environment
The environment uses Makefile. ```-DTEST_MODE``` will run the program in test mode. 
* Unit test files are located in test/ directory. Unit test file naming convention uses ```<cpp_file_name>_unit_test.cpp```
* ```make unittest unit=src/utility.cpp``` will run the unit testing for utility.cpp and its corresponding unit test file in test/utility_unit_test.cpp
* ```make unittest unit=src/phonedata_model.cpp dependency=src/utility.cpp``` will run the unit testing for phonedata_model.cpp with its corresponding unit test file in test/phonedata_model_unit_test.cpp and dependency in src/utility.cpp
* in order to run the program in production mode. comment out ```-DTEST_MODE``` and ```-DDEBUG_TOOL``` in Makefile
* ```bin/Solution <input_file>``` 1 parameter can be added as a parameter of the program. If no input parameter is inputted, the default ```input.csv``` will be used. 

## Lacking implementation and Future improvements
* The last item in output file ```<The phone number of the interlocutor for whom the difference between received and sent messages from this phone number is the greatest>``` was not successfully implemented.
* config.xml assumes that all settings inputted are valid. 
* config.xml input_setting/includes and input.csv should match
* Output file writer is only executed at the end. Future improvement can implement the File writer in a separate thread and output when a certain buffer is reached. 
* I need to improve on my commenting style.

## Performance
Running the command ```time bin/Solution big_file.csv``` with a 100,000 lines file shows the below results.
```
System Unit Specs: Core i5-2400 , 8GB RAM
input file:  big_file.csv
number of lines: 100,000

real    3m36.917s
user    2m2.594s                                                                                   
sys     0m29.719s 

```
Running the same command ```time bin/Solution big_file.csv``` with a 100,000 lines file shows the  below results on a different machine. 

```
System Unit Specs: Core i5-1035G4, 16GB RAM
input file:  big_file.csv
number of lines: 100,000

real	0m36.786s
user	0m34.859s
sys		0m1.406s

```

## About
Solution is also uploaded in my github account earljohn004
https://github.com/earljohn004/phonenumber_cpp_exercise

* Code and Folder structure uses  https://github.com/earljohn004/cppgenericmakefile
* Unit testing framework uses https://github.com/eecs280staff/unit_test_framework
* Config XML parser uses https://github.com/zeux/pugixml


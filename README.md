<h1><b> Scheduling Algorithm OS </b></h1>

<p><i> C program for implementing scheduling algorithm. </i></p>

<ul> 
<li>  <b>This repository contains program used to implement the following problem:</b>  </li>

<p>
  Sudesh Sharma is a Linux expert who wants to have an online system where he can handle student queries. Since there can be multiple     requests at any time he wishes to dedicate a fixed amount of time to every request so that everyone gets a fair share of his time. He   will log into the system from 10am to 12am only. He wants to have separate requests queues for students and faculty, where faculty       queue is given a higher priority. Implement a strategy for the same. The summary at the end of the session should include the total     time he spent on handling queries and average query time.
</p>

<li> <b>  Solution to the problem:  </b> </li>

<p>
The given problem is based upon scheduling algorithm where we have to solving the queries of persons of different classes i.e.<b> Faculty and Students. </b>Thus, these queries can be compared to different processes in terms of operating system where each process has its demands and needs resources and time for its execution. This demands of processes are handled by CPU. In the given situation, Mr. Sudesh Sharma, a Linux expert, can be considered as a CPU, who solves the queries of either Faculty or Student by allocation proper resources to their individual demands and processing them by allocating them time accordingly. Now, Mr. Sharma, wants to provide priority for each query based upon its class, as well as, he wants to dedicate a fixed amount of time to every request. Thus in operating system, if we divide the requests into two separate queues i.e. Faculty and Student such that the first queue contains faculty queries has given higher priority and the second contains student queries which has given lower priority, then we can resolve the problem, by allocation them required resources based upon their priorities as done in the scheduling algorithm in operating systems.

<b>Main() : </b>contains 5 different functions which has their own function to be processed. <br>
<b>Instruction() :</b> guides to follow some points for better functioning.<br>
<b>Input() : </b>takes all the input values required in the program such as no of queries, quantum number, arrival time and burst time.<br>
<b>Ready() : </b>used to put 2 separate queues into single queue according to their priority and arrival time.<br>
<b>Round_robin() :</b> tell the process when to start and when to end.<br>
<b>Printer() :</b> It prints the summary that will be shown to user including average waiting time.<br>

</p>

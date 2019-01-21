# LeetCode

This Coding Interview Preparation Guide is originally from [Sergey Makagonov's facebook post](https://www.facebook.com/notes/sergey-makagonov/another-coding-interview-preparation-guide/10210834096793375/). I have just converted it into a to-do list for myself.

## Algorithms and Data Structures

What operations they allow to perform? What are the runtime complexities?

- [ ] **Sorting**
  - [ ] Quick Sort
  - [ ] Merge Sort
  - [ ] Counting sort
  - [ ] Radix sort
- [x] Binary search
- [x] DFS
- [x] BFS
- [ ] Disjoint Set Union
- [x] Stack
  - [ ] Min/Max stack
- [x] Queue
- [ ] Heap
- [x] Linked list
- [ ] KMP
- [x] Hashes (Rabin-Karp)
- [ ] Segment Tree (?)
- [ ] Binary Indexed Tree (aka Fenwick tree)


## System Design

- [ ] Microservices concepts explained in [Introductory tutorial from NGINX](https://www.nginx.com/blog/introduction-to-microservices/?fbclid=IwAR34oA-gaH02uvG4ke7wuXdl_z37aLPRbT4MezVnesZucqNUpIE2TuIXkEE)

- [ ] [system-design-primer](https://github.com/donnemartin/system-design-primer?fbclid=IwAR03qwxNYbB3MA4WI-gKJ5-7EgeVI1tVsNbiLzQX8twx1K2xxnQKrobd9g0) - nice Github repo with lots of useful material

- [ ] [softwareengineeringdaily.com](http://softwareengineeringdaily.com/?fbclid=IwAR3SD3V1ZrfaXOwbl1FezIC_K-Gd0LPlTzOhA6nCkIItAzhCJ5zmu3az1Oo) podcasts. Some of the recommended ones: 
  - [ ] [ElasticSearch](https://softwareengineeringdaily.com/2017/04/12/elasticsearch-with-philipp-krenn/?fbclid=IwAR0UgjJOAWQz4Br5ASqY3TorHiaUNbFpWwkVUffKN2QuTSqfu7o3GnK5A_0)
  - [ ] [Cassandra](https://softwareengineeringdaily.com/2016/03/10/cassandra-tim-berglund/?fbclid=IwAR2HTqVKkBK0YH_mEDQ_dih_3aBYEWENOibFsjUe7SO6ZbIYoBvJYvabIS0)
  - [ ] [Uber problems with Postgres](https://softwareengineeringdaily.com/2016/09/09/ubers-postgres-problems-with-evan-klitzke/?fbclid=IwAR1OacOLTobHIKDP5vL19_1Xl8SqM8ET6JK-gEZGlcbIUSFEwcZ4q3pgyIQ)
  - [ ] [Relational databases](https://softwareengineeringdaily.com/2016/09/08/relational-databases-with-craig-kerstiens/?fbclid=IwAR37YgSA9qUbY60KzUKtI2kPmhDOmOQZTB4_v7IyubIaX5BCBHJOvWceSnY)
- [ ] [Designing Data Intensive Applications](https://www.amazon.com/dp/1449373321?fbclid=IwAR1T8KGO5E_iminqYVkKQ2HXnqvm82DH_1KzTebjQceEozvNcEDABc99ehc) book about scalability.
- [ ] Cassandra highly scalable noSQL database. DataStax Enterprise course and tutorial:
  - [ ] [course](https://academy.datastax.com/courses?fbclid=IwAR2FMfhvXZEl382YIS1wP9UpfEiACji98XZwT9KGKZy0L3YNDaxQvmJ_g9k)
  - [ ] [tutorial](http://docs.datastax.com/en/cassandra/3.0/?fbclid=IwAR1WsnC-0dtHZUZOWVYnao3Q3XzkkntqJlpB_9T-WeXu5p-P1rYwiOZaHIU)
- [ ] Messaging systems - read about XMPP
  - [ ] [Part 1](https://engineering.riotgames.com/news/chat-service-architecture-protocol?fbclid=IwAR0iy0BoOKKKw23vocjCzRUFWDPw9IkmbqWiM-eZ_M3bObW12cgHXzWTRpg)
  - [ ] [Part 2](https://engineering.riotgames.com/news/chat-service-architecture-servers?fbclid=IwAR2agefi_o_YFdB6beH3iCeb65m4ZLCHOgBjn3eCX1vx9WnB5NP-pC1PfdM)
  - [ ] [Part 3](https://engineering.riotgames.com/news/chat-service-architecture-persistence?fbclid=IwAR1JgFIMFcxqWpLz2TvwVDE_mTDSLKPM_EYS3JAeDMFI8H4suofPqtn-fvM)
  - [ ] [Video overview](https://www.youtube.com/watch?v=_jsMpmWaq7I&fbclid=IwAR3E2ux2G4FFnbxKOxq9-tZtjgyypOyzUSckHE3wzzlOMFCIAPbCufqpmpw)
- [ ] Yelp open-sourced their data pipeline, and also wrote a [series of blog posts](https://engineeringblog.yelp.com/2016/07/billions-of-messages-a-day-yelps-real-time-data-pipeline.html?fbclid=IwAR3tkwe7BsyDt1jOxRBNKqwh0nv5AIUzBjEWkzL4vByukpzrl8n7YvGFNvw) about it.
- [ ] [A nice youtube playlist](https://www.youtube.com/watch?v=oSdaEQnlUpY&index=1&list=PLhr1KZpdzukdeX8mQ2qO73bg6UKQHYsHb&fbclid=IwAR3NnHbGRA1PwnSbb9VFlCEx25_xF4MjpVAoZ7q4_hGtC7i9zQBXFNewqkU) with short videos, where people share how they use AWS in their projects. Featuring Slack, BBC, Lyft and other companies.
- [ ] [50-minute episode](https://www.youtube.com/watch?v=As2gOXtcPVQ&fbclid=IwAR2dMzwe1SMAbnqiw1RBTlCVhVy5l9Xz9FPYfU_9up_6A-xtjbvLtlzucQY) from Jackson Gabbard (former employee and interviewer at Facebook). He gives some good tips on how to tackle problems and what interviewers expect from you.
- [ ] Legendary papers from Google and Amazon: Bigtable, DynamoDB, GFS, Anatomy of search engine. Many people recommend them.
  - [ ] [Bigtable](https://static.googleusercontent.com/media/research.google.com/en//archive/bigtable-osdi06.pdf?fbclid=IwAR2vjPP-twukggdqh52zANeuB_1G57GmMiChQwiR1uyGxUGIB2lkE_p6RQA)
  - [ ] [DynamoDB](https://www.allthingsdistributed.com/files/amazon-dynamo-sosp2007.pdf?fbclid=IwAR2d2blVpJdM5hAOURcCzSMxiKvHN0wb7HnwLEPxGdo_mRd84XEHnH1zHYA)
  - [ ] [GFS](https://static.googleusercontent.com/media/research.google.com/en//archive/gfs-sosp2003.pdf?fbclid=IwAR0W6w8gebsFoxycBLVxEMn7oB0o49SBC9hc7xaK3HVH6l2r11LxI0AJL_4)
  - [ ] [Anatomy](http://ilpubs.stanford.edu:8090/361/1/1998-8.pdf?fbclid=IwAR1MgddT1_bOcNGd9ZlyXSYdk_rb4eion4tQOvNICmtZTWlKiEzLVr9GhPg)

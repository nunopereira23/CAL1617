/*
 * matcher.h
 *
 *  Created on: 20/05/2017
 *      Author: nuno1
 */

#ifndef SRC_MATCHER_H_
#define SRC_MATCHER_H_

void pre_kmp(std::string pattern, std::vector<int> & prefix);
int kmp(std::string text, std::string pattern);
int numStringMatching(std::string filename, std::string toSearch);
int editDistance(std::string pattern, std::string text);
int editDistance(std::string pattern, std:: string text);





#endif /* SRC_MATCHER_H_ */

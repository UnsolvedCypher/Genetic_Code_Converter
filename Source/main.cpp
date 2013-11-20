#include <iostream>

using namespace std;
string GetComplimentaryStrand(string dnastrand);
string GetInput();
string GetmRNASequence(string dnastrand);
string GetProteinFragment(string dnastrand);
void Output(string what_to_output);

int main()
{
  while(true) {
    string original_dna = GetInput();
    cout << "Original DNA: \n\n";
    Output(original_dna);
    cout << "\n\nComplimentary DNA strand: \n\n";
    string complimentary_strand = GetComplimentaryStrand(original_dna);
    Output(complimentary_strand);
    cout << "\n\nmRNA Sequence: \n\n";
    string m_rna_strand = GetmRNASequence(complimentary_strand);
    Output(m_rna_strand);
    cout << "\n\nProtein Fragment: \n\n";
    Output(GetProteinFragment(m_rna_strand));
    cout << "\n\n";
  }
    return 0;
}
string GetInput() {
  cout << "Please enter your DNA strand (in all caps): " << endl;
  string dnastrand;
  cin >> dnastrand;
  return dnastrand;
}
string GetComplimentaryStrand(string dnastrand) {
  string complimentarystrand;
  complimentarystrand.resize(dnastrand.size());
  for (int i = 0; i < (int)dnastrand.length(); i++) {
      //cout << dnastrand[i];
    switch (dnastrand[i]) {
    case 'A':
      complimentarystrand[i] = 'T';
      //cout << "T";
      break;
    case 'T':
      complimentarystrand[i] = 'A';
      break;
    case 'G':
      complimentarystrand[i] = 'C';
      break;
    case 'C':
      complimentarystrand[i] = 'G';
      break;
    default:
      cout << "Error!!!";
      break;
    }
    //cout << complimentarystrand;
  }
  return complimentarystrand;
}
string GetmRNASequence(string dnastrand) {
  string m_rna_sequence;
  m_rna_sequence.resize(dnastrand.length());
  for (int i = 0; i < (int)dnastrand.length(); i++) {
    if (dnastrand[i] == 'T') {
      m_rna_sequence[i] = 'U';
    } else {
      m_rna_sequence[i] = dnastrand[i];
    }
  }
  return m_rna_sequence;
}
string GetProteinFragment(string dnastrand) {
  string protein_fragment;
  protein_fragment.resize(dnastrand.length() / 3);
  for (int i = 0; i < (int)dnastrand.length() / 3; i++) {
    string triplet = dnastrand.substr((3*i), 3);
    if (triplet == "UUU" || triplet == "UUC") {
      protein_fragment[i] = 'P';
    } else if (triplet == "UUA"
               || triplet == "UUG"
               || triplet == "CUU"
               || triplet == "CUC"
               || triplet == "CUA"
               || triplet == "CUG") {
      protein_fragment[i] = 'L';
    } else if (triplet == "AUU"
               || triplet == "AUC"
               || triplet == "AUA") {
      protein_fragment[i] = 'I';
    } else if (triplet == "AUG") {
      protein_fragment[i] = 'M';
    } else if (triplet == "GUU"
               || triplet == "GUC"
               || triplet == "GUA"
               || triplet == "GUG" ) {
      protein_fragment[i] = 'V';
    } else if (triplet == "UCU"
               || triplet == "UCC"
               || triplet == "UCA"
               || triplet == "AGC"
               || triplet == "AGU"
               || triplet == "UCG") {
      protein_fragment[i] = 'S';
    } else if (triplet == "CCU"
               || triplet == "CCC"
               || triplet == "CCA"
               || triplet == "CCG" ) {
      protein_fragment[i] = 'P';
    } else if (triplet == "ACA"
               || triplet == "ACU"
               || triplet == "ACC"
               || triplet == "ACG" ) {
      protein_fragment[i] = 'T';
    } else if (triplet == "GCU"
               || triplet == "GCC"
               || triplet == "GCA"
               || triplet == "GCG" ) {
      protein_fragment[i] = 'A';
    } else if (triplet == "UAU"
               || triplet == "UAC") {
      protein_fragment[i] = 'Y';
    } else if (triplet == "UAA"
               || triplet == "UAG"
               || triplet == "UGA") {
      protein_fragment[i] = '*';
    } else if (triplet == "CAU"
               || triplet == "CAC") {
      protein_fragment[i] = 'H';
    } else if (triplet == "CAA"
               || triplet == "CAG") {
      protein_fragment[i] = 'Q';
    } else if (triplet == "AAU"
               || triplet == "AAC") {
      protein_fragment[i] = 'N';
    } else if (triplet == "AAA"
               || triplet == "AAG") {
      protein_fragment[i] = 'K';
    } else if (triplet == "GAU"
               || triplet == "GAC") {
      protein_fragment[i] = 'D';
    } else if (triplet == "GAA"
               || triplet == "GAG") {
      protein_fragment[i] = 'E';
    } else if (triplet == "UGU"
               || triplet == "UGC") {
      protein_fragment[i] = 'C';
    } else if (triplet == "CGU"
               || triplet == "CGC"
               || triplet == "CGA"
               || triplet == "CGG"
               || triplet == "AGA"
               || triplet == "AGG") {
      protein_fragment[i] = 'R';
    } else if (triplet == "GGC"
               || triplet == "GGU"
               || triplet == "GGA"
               || triplet == "GGG") {
      protein_fragment[i] = 'G';
    } else if (triplet == "UGG") {
      protein_fragment[i] = 'W';
    } else {
      cout << "Error with triplet " << triplet << endl;
    }
  }
  return protein_fragment;
}
void Output(string what_to_output) {
  for (int i = 0; i < (int) what_to_output.length(); i++) {
    cout << what_to_output[i] << " ";
  }
}

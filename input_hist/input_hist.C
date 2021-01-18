void input_hist()
{
	TH1F *hist1 = new TH1F ("hist1", "Grade Distribution", 8, 1, 9);


	fstream file;
	file.open("data_ih.txt", ios::in);
	
	double value;

	while(1)
	{
		file >> value;
		hist1->Fill(value);
		if(file.eof()) break;
	}

	file.close();

	hist1->GetXaxis()->SetTitle("Grade");
	hist1->GetYaxis()->SetTitle("Number");

	TCanvas *c1 = new TCanvas ();
	hist1->Draw();
}

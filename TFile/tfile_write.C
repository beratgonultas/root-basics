void tfile_write() 
{
	TFile *file = new TFile("output.root", "RECREATE");

	TH1F *hist = new TH1F("hist", "Histogram", 100, 0, 200);
	
	hist->Fill(10);
	hist->Fill(100);
	
	file->Write();
		
	file->Close();

}

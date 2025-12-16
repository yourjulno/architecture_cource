import json
import csv
import yaml
from abc import ABC, abstractmethod


class DataImporter(ABC):
    @abstractmethod
    def parse_data(self, data: str):
        pass

    def import_data(self, file_path: str):
        with open(file_path, 'r') as file:
            data = file.read()
            return self.parse_data(data)


class JSONImporter(DataImporter):
    def parse_data(self, data: str):
        return json.loads(data)


class CSVImporter(DataImporter):
    def parse_data(self, data: str):
        lines = data.splitlines()
        return list(csv.DictReader(lines))


class YAMLImporter(DataImporter):
    def parse_data(self, data: str):
        return yaml.safe_load(data)
